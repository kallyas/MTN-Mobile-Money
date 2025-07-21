#!/usr/bin/env python3
import subprocess
import os
import sys

def clean_data_files():
    """Remove existing data files before tests"""
    files_to_remove = ['user.dat', 'favorites.dat']
    for file in files_to_remove:
        if os.path.exists(file):
            os.remove(file)
            print(f"Removed {file}")

def run_app_with_input(input_sequence, timeout=10):
    """Run the app with given input sequence"""
    try:
        process = subprocess.Popen(
            ['./build/mtn'],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        
        stdout, stderr = process.communicate(input=input_sequence, timeout=timeout)
        return stdout, stderr, process.returncode
    
    except subprocess.TimeoutExpired:
        process.kill()
        return None, f"Process timed out after {timeout} seconds", -1
    except Exception as e:
        return None, str(e), -1

def test_basic_functionality():
    """Test basic registration and exit"""
    print("\n=== Test 1: Basic Registration and Exit ===")
    clean_data_files()
    
    # Input: Register user -> Exit
    input_sequence = "1\nJohnDoe\n+256701234567\n5000\n10\n"
    
    stdout, stderr, returncode = run_app_with_input(input_sequence)
    
    if stdout is None:
        print(f"❌ Test failed: {stderr}")
        return False
    
    print("STDOUT:")
    print(stdout)
    if stderr:
        print("STDERR:")
        print(stderr)
    
    # Check if registration was successful
    if "Registration successful!" in stdout:
        print("✅ Registration successful")
    else:
        print("❌ Registration failed")
        return False
    
    # Check if user.dat was created
    if os.path.exists('user.dat'):
        print("✅ User data file created")
    else:
        print("❌ User data file not created")
        return False
    
    return True

def test_existing_user_login():
    """Test logging in with existing user"""
    print("\n=== Test 2: Existing User Login ===")
    
    # Don't clean data files - use existing user from previous test
    if not os.path.exists('user.dat'):
        print("❌ No existing user data - run test 1 first")
        return False
    
    # Input: Check balance -> Exit
    input_sequence = "9\n10\n"
    
    stdout, stderr, returncode = run_app_with_input(input_sequence)
    
    if stdout is None:
        print(f"❌ Test failed: {stderr}")
        return False
    
    print("STDOUT:")
    print(stdout)
    
    # Check if user is welcomed back
    if "Welcome back" in stdout:
        print("✅ User welcomed back")
    else:
        print("❌ User not welcomed back")
        return False
    
    # Check if balance is shown
    if "Your current balance is" in stdout:
        print("✅ Balance displayed")
    else:
        print("❌ Balance not displayed")
        return False
    
    return True

def test_invalid_choice():
    """Test invalid menu choice handling"""
    print("\n=== Test 3: Invalid Menu Choice ===")
    
    # Input: Invalid choice -> Exit
    input_sequence = "99\n10\n"
    
    stdout, stderr, returncode = run_app_with_input(input_sequence)
    
    if stdout is None:
        print(f"❌ Test failed: {stderr}")
        return False
    
    print("STDOUT:")
    print(stdout)
    
    # Check if invalid choice message is shown
    if "Invalid choice" in stdout:
        print("✅ Invalid choice handled correctly")
        return True
    else:
        print("❌ Invalid choice not handled properly")
        return False

def main():
    """Run all tests"""
    print("MTN Mobile Money E2E Tests")
    print("=" * 40)
    
    # Build the application first
    print("Building application...")
    build_result = subprocess.run(['make', 'clean'], capture_output=True, text=True)
    build_result = subprocess.run(['make'], capture_output=True, text=True)
    
    if build_result.returncode != 0:
        print("❌ Build failed:")
        print(build_result.stdout)
        print(build_result.stderr)
        return 1
    
    print("✅ Build successful")
    
    # Run tests
    tests = [
        test_basic_functionality,
        test_existing_user_login,
        test_invalid_choice
    ]
    
    passed = 0
    failed = 0
    
    for test in tests:
        try:
            if test():
                passed += 1
            else:
                failed += 1
        except Exception as e:
            print(f"❌ Test {test.__name__} crashed: {e}")
            failed += 1
    
    print("\n" + "=" * 40)
    print(f"Tests Summary: {passed} passed, {failed} failed")
    
    if failed == 0:
        print("🎉 All tests passed!")
        return 0
    else:
        print("❌ Some tests failed")
        return 1

if __name__ == "__main__":
    sys.exit(main())