# MTN Mobile Money Application

This is a command-line interface (CLI) application simulating basic MTN Mobile Money functionalities. It allows users to register, deposit, withdraw, transfer money, check their balance, and manage favorites.

## Features

- User Registration and Data Persistence
- Deposit Funds
- Withdraw Funds
- Transfer Funds to Mobile Users
- Check Account Balance
- Manage Favorite Contacts

## Project Structure

- `src/`: Contains all source code (`.c` files) and header files (`.h`).
- `build/`: Contains compiled object files and the final executable.
- `user.dat`: Binary file for storing user data.
- `favorites.dat`: Binary file for storing favorite contacts.

## Building the Application

To build the application, navigate to the root directory of the project and run `make`:

```bash
make
```

This will compile the source files and create an executable named `mtn` in the `build/` directory.

## Running the Application

After building, you can run the application from the root directory:

```bash
./build/mtn
```

## Future Enhancements

- Implement remaining menu options (Airtime & Bundles, MomoPay, Payments, Savings & Loans, Financial Services, East Africa, Rest of Africa, Send With Care, Donations).
- Improve input validation and error handling.
- Enhance security (e.g., password protection, transaction PINs).
- Implement a more robust data storage solution (e.g., database).
- Add more comprehensive unit and integration tests.