# Customer Data Processing Tool

A command-line application written in C++ that reads customer records from a CSV file, filters customers by a minimum number of purchases, sorts the matching records, and exports the results to a new CSV file.

## Features

- Read customer records from a CSV file using C++ file streams.
- Filter customers whose purchase count is greater than or equal to a user-provided threshold.
- Sort matching customers by purchase count in ascending order.
- Export filtered and sorted records to `result.csv`.
- Separate file I/O, filtering, and program flow into multiple source and header files.

## Technologies

- C++ (C++17 compatible)
- C++ Standard Library: `vector`, `string`, `fstream`, `sstream`, `algorithm`

## Project Structure

```text
.
├── main.cpp
├── CustomerDatabase.hpp
├── CustomerDatabase.cpp
├── filterByMinPurchases.hpp
├── filterByMinPurchases.cpp
└── README.md
```

- `main.cpp`: Handles user input, coordinates filtering and sorting, and writes the output file.
- `CustomerDatabase.hpp/.cpp`: Defines the customer record and functions for reading and writing CSV files.
- `filterByMinPurchases.hpp/.cpp`: Implements filtering by minimum purchase count.

## Build and Run

Compile all three `.cpp` files from the project directory:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp CustomerDatabase.cpp filterByMinPurchases.cpp -o customer_tool
```

Run on Linux or macOS (including WSL):

```bash
./customer_tool
```

On Windows, if compiling to `customer_tool.exe`, run:

```powershell
.\customer_tool.exe
```

When prompted, enter the path to your input CSV file and the minimum number of purchases.

## Input Format

The input file should contain **no header row** and one customer per line, with three comma-separated fields:

```text
email,number_of_purchase,name
```

Example `customers.csv`:

```csv
alice@example.com,5,Alice
bob@example.com,2,Bob
charlie@example.com,8,Charlie
```

## Example Usage

```text
Enter the file name: customers.csv
Enter the number of purchase: 4
```

The program creates `result.csv` in the current working directory:

```csv
alice@example.com, 5, Alice
charlie@example.com, 8, Charlie
```

Only customers with at least four purchases are included, ordered by purchase count from lowest to highest.

## How It Works

1. Open the input CSV file with `std::ifstream`.
2. Parse each nonempty line into a `customer` record using `std::stringstream`.
3. Store records in a `std::vector<customer>`.
4. Filter records using `search()` and the minimum purchase threshold.
5. Sort the matching records with `std::sort()` and a lambda comparator.
6. Write the results to `result.csv` using `std::ofstream`.

## Current Limitations

- Assumes a simple, headerless CSV format; quoted fields containing commas are not supported.
- Invalid purchase counts may cause an uncaught exception from `std::stoi()`.
- Does not currently validate nonnumeric input for the purchase threshold.
- Loads all customer records into memory before filtering.
- Does not support adding, editing, or deleting customer records.

## Potential Improvements

- Add input validation and error handling for malformed CSV records.
- Add automated tests for parsing, filtering, and sorting.
- Support quoted CSV fields and optional header rows.
- Allow users to specify the output file path.

## License

No license has been specified yet.
