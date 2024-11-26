import os
import subprocess
from pathlib import Path

def run_tests(tests_dir, command):
    # Iterate through all test folders

    for test_folder in Path(tests_dir).iterdir():
        if test_folder.name == "__pycache__":
            continue
        if test_folder.is_dir():  # Ensure it's a directory
            input_file = test_folder / "input"
            expected_file = test_folder / "expected_output"

            # Ensure input and expected files exist
            if not input_file.exists() or not expected_file.exists():
                print(f"Skipping {test_folder.name}: Missing input or expected_output file.")
                continue

            # Read input and expected output
            with open(input_file, "r") as infile, open(expected_file, "r") as expfile:
                input_data = infile.read()
                expected_output = expfile.read()

            # Run the command with input
            try:
                result = subprocess.run(
                    command, input=input_data, text=True, capture_output=True,
                    timeout=2.0
                )

                # Compare actual output with expected output
                if result.stdout.strip() == expected_output.strip():
                    print(f"{test_folder.name}: PASSED")
                else:
                    print(f"{test_folder.name}: FAILED")
                    print(f"Expected:\n{expected_output}")
                    print(f"Got:\n{result.stdout}")
            except:
                print(f"{test_folder.name}: TIMEOUT")

# Example usage
tests_directory = "tests"  # Path to your tests folder
command_to_test = "cmake-build-debug/warehouse"  # Replace with the command you're testing
run_tests(tests_directory, command_to_test)
