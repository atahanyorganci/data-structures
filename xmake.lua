set_project("data-structures", {version = "1.0.0"})
set_xmakever("2.8.0")
set_languages("c++17")

-- Use the plain clang toolchain so the build does not add -target/-isysroot by default.
-- That combination can break when a Nix-provided libc++ is mixed with the Xcode SDK.
set_toolchains("clang")

set_policy("check.auto_ignore_flags", false)
add_cxxflags("-Wall", "-Wextra", "-Werror")

add_requires("catch2")

-- Release archive: -O3 (src uses only project headers)
target("lib_release")
    set_kind("static")
    set_default(true)
    set_targetdir("dist/release")
    set_filename("release.lib")
    add_files("src/*.cpp")
    add_includedirs("include")
    set_symbols("none")
    add_cxxflags("-O3")
    on_clean(function ()
        if os.isdir("dist") then
            os.rm("dist")
        end
    end)

-- Debug archive: -g; Makefile used only -Iinclude for debug objects
target("lib_debug")
    set_kind("static")
    set_targetdir("dist/debug")
    set_filename("debug.lib")
    add_files("src/*.cpp")
    add_includedirs("include")
    add_cxxflags("-g")

target("test")
    set_kind("binary")
    set_targetdir("dist/test")
    set_filename("test.out")
    add_deps("lib_debug")
    add_files("test/*.cpp")
    add_includedirs("include")
    add_cxxflags("-g")
    add_packages("catch2", {components = {"main", "lib"}})

target("lint")
    set_kind("phony")
    on_build(function ()
        local paths = {}
        for _, p in ipairs(os.files("src/**.cpp")) do
            table.insert(paths, p)
        end
        for _, p in ipairs(os.files("test/**.cpp")) do
            table.insert(paths, p)
        end
        for _, p in ipairs(os.files("include/**.h")) do
            table.insert(paths, p)
        end
        if #paths > 0 then
            local argv = {"-i"}
            for _, p in ipairs(paths) do
                table.insert(argv, p)
            end
            os.execv("clang-format", argv)
        end
    end)
