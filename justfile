default_preset := "gcc-debug"

# Lists the available presets
list-presets:
    cmake --list-presets

# Configure the provided preset
configure preset=default_preset *args:
    cmake --preset {{preset}} {{args}}

# Build the given preset
# Note: this does not run the configure step!
build preset=default_preset *args:
    cmake --build --preset {{preset}} {{args}}

# Run the tests for the given preset
test preset=default_preset *args: build
    ctest --preset {{preset}} {{args}}

# Runs the configure, build and test steps for the given preset
workflow preset=default_preset *args:
    cmake --workflow --preset {{preset}} {{args}}

# Cleans the build directory for the given preset
clean preset=default_preset:
    cmake --build --preset {{preset}} --target clean