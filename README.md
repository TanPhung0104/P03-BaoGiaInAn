
# Printing Quotation Management System

## 1. Project Overview

The Printing Quotation Management System is a console-based application developed in C for the PRF192 course project.

The purpose of this project is to help a club manage printing orders, calculate printing quotations, compare printing costs with a budget, search for and delete orders, sort orders by final price, and generate statistics.

The system supports both black-and-white and color printing, with discounts based on the total number of sheets.

## 2. Project Objectives

- Manage printing orders efficiently.
- Validate order information and prevent duplicate order IDs.
- Calculate the number of sheets and printing costs.
- Apply discounts according to the number of sheets.
- Compare black-and-white and color printing costs with a given budget.
- Search for, edit, and delete printing orders.
- Sort orders by final price in ascending order.
- Generate statistics for printing orders.

## 3. Technologies

- **Programming language:** C
- **Compiler:** GCC
- **Code editor:** Visual Studio Code
- **Version control:** Git
- **GitHub client:** GitHub Desktop

## 4. Team Members and Responsibilities

| No. | Student Name | Student ID | Responsibilities |
|---|---|---|---|
| 1 | Lê Quang Trí | QE200016 | Manage printing orders, including adding and editing orders and validating input data. |
| 2 | Nguyễn Tấn Phụng | QE210072 | Calculate sheet quantities, original printing costs, and final prices after discounts. |
| 3 | Châu Đông Anh | QE210061 | Compare black-and-white and color printing costs with the available budget. |
| 4 | Trần Quốc Kiệt | QE210232 | Implement order searching, deletion, sorting, and statistics. |

### Team Collaboration

Each member is assigned responsibility for a specific module. The modules are integrated into one application using shared declarations and function prototypes in `common.h`.

The team also works on integration, compilation, functional testing, and fixing issues identified during development.

## 5. Printing Rules and Pricing

### 5.1. Input Information

Each printing order contains:

- Order ID
- Order name
- Number of pages
- Number of copies
- Printing type

The program supports up to 100 orders.

The number of pages and copies must each be between 1 and 1,000.

### 5.2. Printing Rates

| Printing Type | Price per Sheet |
|---|---:|
| Black-and-white | 1.00 thousand VND |
| Color | 3.00 thousand VND |

### 5.3. Discount Rules

| Total Number of Sheets | Discount Rate |
|---|---:|
| Fewer than 100 sheets | 0% |
| From 100 to 499 sheets | 5% |
| 500 sheets or more | 10% |

### 5.4. Calculation Formulas

**Number of sheets**

Number of sheets = Number of pages × Number of copies

**Original price**

Original price = Number of sheets × Price per sheet

**Final price**

Final price = Original price × (1 − Discount rate)

All prices are displayed in thousand Vietnamese dong (VND), with two decimal places.

## 6. Main Features

### 6.1. Add Printing Orders

- Enter order information.
- Check whether the order ID already exists.
- Validate the number of pages and copies.
- Add a valid order to the list.

### 6.2. Edit Printing Orders

- Find an existing order.
- Update its information.
- Validate the new information before saving changes.

### 6.3. Calculate Printing Quotations

- Calculate the total number of sheets.
- Calculate the original printing price.
- Apply the appropriate discount.
- Display the final quotation.

### 6.4. Compare Budgets

- Select an existing order.
- Enter the available budget.
- Calculate the costs of black-and-white and color printing.
- Display whether each option fits the budget and the remaining or missing amount.

### 6.5. Search for Orders

Search for a printing order using its ID and display the corresponding result.

### 6.6. Delete Orders

Find and remove an order from the list.

### 6.7. Sort Orders

Sort printing orders by final price in ascending order.

### 6.8. Generate Statistics

Display printing-order statistics by printing type.

## 7. Project Structure

| File | Description |
|---|---|
| `main.c` | Contains the main function and program menu. |
| `common.h` | Defines shared constants, global variables, and function prototypes. |
| `quan_ly_don.c` | Implements adding and editing printing orders. |
| `tinh_bao_gia.c` | Implements sheet-count, original-price, and final-price calculations. |
| `so_sanh_ngan_sach.c` | Implements budget comparison for different printing types. |
| `tim_xoa_sap_xep.c` | Implements searching, deleting, sorting, listing orders, and statistics. |

## 8. Compilation and Execution

### 8.1. Requirements

- GCC compiler installed.
- Visual Studio Code or another C editor.
- All project source files in the same project directory.

### 8.2. Compile the Program

Open the project folder in Visual Studio Code and open the terminal.

Run the following command:

```bash
gcc -Wall -Wextra main.c quan_ly_don.c so_sanh_ngan_sach.c tim_xoa_sap_xep.c tinh_bao_gia.c -o bao_gia.exe
```

The `-Wall -Wextra` options enable additional compiler warnings.

### 8.3. Run the Program

In Windows PowerShell, enter:

```powershell
.\bao_gia.exe
```

### 8.4. Main Menu

The program provides the following options:

1. Add a printing order.
2. Edit a printing order.
3. Calculate printing quotations.
4. Compare printing costs with a budget.
5. Search for a printing order.
6. Delete a printing order.
7. Sort printing orders.
8. Generate statistics.
0. Exit the program.

## 9. Testing and Results

Twelve test cases were executed to verify the main functions of the program.

| Test Case | Test Description | Expected Result | Actual Result | Status |
|---|---|---|---|---|
| TC01 | Add a valid order: JOB001, 10 pages, 2 copies, black-and-white | The order is added successfully. | The program displayed a success message. | PASS |
| TC02 | Add another order using the existing ID JOB001 | The duplicate ID is rejected. | The program displayed a duplicate-ID warning and requested another ID. | PASS |
| TC03 | Enter 0 pages for JOB002 | The invalid page count is rejected. | The program displayed a validation message and requested the page count again. | PASS |
| TC04 | Enter 1,001 copies | The invalid copy count is rejected. | The program displayed a validation message and requested the copy count again. | PASS |
| TC05 | Calculate the price for 99 black-and-white sheets | Final price: 99.00 thousand VND. | The displayed price was 99.00 thousand VND. | PASS |
| TC06 | Calculate the price for 100 black-and-white sheets | Final price: 95.00 thousand VND. | The displayed price was 95.00 thousand VND. | PASS |
| TC07 | Calculate the price for 100 color sheets (JOB008) | Final price: 285.00 thousand VND. | The displayed price was 285.00 thousand VND. | PASS |
| TC08 | Calculate the price for 499 black-and-white sheets | Final price: 474.05 thousand VND. | The displayed price was 474.05 thousand VND. | PASS |
| TC09 | Calculate the price for 500 black-and-white sheets | Final price: 450.00 thousand VND. | The displayed price was 450.00 thousand VND. | PASS |
| TC10 | Search for nonexistent order ID JOB999 | The program reports that the order cannot be found. | The program displayed a not-found message. | PASS |
| TC11 | Compare JOB006 with a budget of 200.00 thousand VND | Black-and-white printing fits the budget; color printing exceeds it. | Black-and-white cost was 95.00; color cost was 285.00 thousand VND. | PASS |
| TC12 | Sort existing orders by final price | Orders are displayed in ascending order of final price. | The program displayed a successful sorting message and the orders in ascending price order. | PASS |

### 9.1. Budget Comparison Details

For TC11, order JOB006 contains 100 sheets and the available budget is 200.00 thousand VND.

| Item | Amount |
|---|---:|
| Black-and-white printing | 95.00 thousand VND |
| Remaining budget for black-and-white printing | 105.00 thousand VND |
| Color printing | 285.00 thousand VND |
| Additional budget needed for color printing | 85.00 thousand VND |
| Difference between the two printing prices | 190.00 thousand VND |

The program correctly indicated that black-and-white printing fits the budget, while color printing exceeds the budget.

### 9.2. Sorting Results

For TC12, the program sorted the six existing orders by final price in ascending order.

| Position | Order ID | Final Price (thousand VND) |
|---:|---|---:|
| 1 | JOB007 | 3.00 |
| 2 | JOB006 | 95.00 |
| 3 | JOB005 | 99.00 |
| 4 | JOB008 | 285.00 |
| 5 | JOB010 | 450.00 |
| 6 | JOB009 | 474.05 |

The displayed order matched the expected ascending order.

### 9.3. Testing Summary

- Total recorded test cases: 12
- Passed test cases: 12
- Failed test cases: 0

The results above describe the twelve test cases actually executed. Additional tests are needed to cover all possible input conditions and features.

## 10. Limitations

- The application uses a console-based interface.
- Order information is stored in memory during program execution.
- Order data is not permanently saved after the program exits.
- Additional tests are needed for editing, deletion, statistics, empty lists, maximum capacity, and other boundary conditions.
- The current testing set focuses on selected normal cases, invalid inputs, pricing boundaries, budget comparison, searching, and sorting.

## 11. Conclusion

The Printing Quotation Management System applies fundamental C programming concepts to a practical printing-order management problem.

The project includes input validation, modular programming, printing-price calculations, discount rules, budget comparison, searching, deletion, sorting, and statistics.

The twelve recorded test cases passed, confirming the expected behavior of the specific scenarios tested. Further testing and persistent data storage could improve the system in future versions.
