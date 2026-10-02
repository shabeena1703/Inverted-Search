# 🔎 Inverted Search

---

## 📝 Brief Summary

The **Inverted Search** project is implemented in C using a **Hash Table and Linked Lists**. It creates an inverted database that stores each word, the files in which it appears, and the number of times it occurs in each file.

### 🔍 Normal Search vs Inverted Search

**Normal Searching:**

```text
f1.txt → search "hi" → check file
f2.txt → search "hi" → check file
f3.txt → search "hi" → check file
```

For every search, each file needs to be checked.

**Inverted Searching:**

```text
                    "hi"
                      │
          ┌───────────┼───────────┐
          ↓           ↓           ↓
        f1.txt      f2.txt      f3.txt
          3           1           1
```

The inverted database already stores the files and occurrence counts for each word, so the required information can be retrieved directly.

---

## 🎯 Features

* Validate input `.txt` files
* Create an inverted database
* Store words using a hash table
* Store multiple files for each word
* Store occurrence count for each file
* Search for a word
* Display the complete database
* Save the database into a file
* Update the database with new files

---

## 📊 Data Structure

The project combines a **Hash Table + Linked Lists**:

```text
                    HASH TABLE
                        │
        ┌───────────────┼───────────────┐
        ↓               ↓               ↓
     Index 0          Index 7         Index 14
        │               │               │
       are              hi              ok?
        │               │               │
     ┌──┴──┐       ┌────┼────┐           │
     ↓     ↓       ↓    ↓    ↓           ↓
   f2.txt f3.txt f1.txt f2.txt f3.txt  f3.txt
     1     1         3    1    1         1
```

### Structure

* **Hash Table** → Stores data based on the calculated hash index.
* **Main Node** → Stores the word and its file count.
* **Sub Nodes** → Store file names and the occurrence count of the word in each file.
* **Linked Lists** → Connect multiple words and multiple files.

---

## 📁 Project Structure

```text
Inverted-Search/
│
├── main.c
├── main.h
├── create_database.c
├── display_database.c
├── search_database.c
├── save_database.c
├── update_database.c
├── validate.c
└── README.md
```

---

## 🛠️ Technologies Used

* **Language:** C
* **Compiler:** GCC
* **Operating System:** Linux / WSL
* **Data Structures:** Hash Table, Linked Lists
* **Concepts:** File Handling, Dynamic Memory Allocation, Pointers, Structures

---

## 🔄 Program Flow

```text
                    START
                      │
                      ↓
              Read input .txt files
                      │
                      ↓
                Validate files
                      │
                      ↓
              Create file list
                      │
                      ↓
              Create Hash Table
                      │
                      ↓
              Read words from files
                      │
                      ↓
              Calculate hash index
                      │
                      ↓
             Store word in database
                      │
                      ↓
          Store file name + word count
                      │
                      ↓
        ┌─────────────┼─────────────┐
        ↓             ↓             ↓
     Search         Display        Save
        │             │             │
        └─────────────┼─────────────┘
                      ↓
                    Update
                      │
                      ↓
                     EXIT
```

**Main Operations**

```text
Create Database
      ↓
Read files
      ↓
Extract words
      ↓
Calculate hash index
      ↓
Store word + file + count


Search Word
      ↓
Enter word
      ↓
Calculate hash index
      ↓
Search word
      ↓
Display files + occurrence count


Save Database
      ↓
Hash Table
      ↓
Save database information
      ↓
database.txt


Update Database
      ↓
Read saved database
      ↓
Add new files
      ↓
Update existing database
```

---

## 🚀 How to Run

**1. Compile the project**

```bash
gcc *.c
```

**2. Run the program with input files**

```bash
./a.out f1.txt f2.txt f3.txt
```

**3. Select an operation**

```text
=====================================MENU===================================
1. Create Database
2. Display Database
3.Search Word
4. Save Database
5. Update Database
6. Exit
===========================================================================
```

---

# 📦 Output

**1️⃣ File Validation**

When the program starts, the input files are validated and inserted into the file list.

```text
Validation success for f1.txt
insertion of f1.txt is done
Head -> f1.txt -> NULL

Validation success for f2.txt
insertion of f2.txt is done
Head -> f1.txt-> f2.txt -> NULL

Validation success for f3.txt
insertion of f3.txt is done
Head -> f1.txt-> f2.txt-> f3.txt -> NULL
```

---

**2️⃣ Create Database**

Select:

```text
1
```

Output:

```text
INFO : DATABASE IS CREATED SUCCESSFULLY
```

---

**3️⃣ Display Database**

Select:

```text
2
```

Output:

```text
------------------------------------------------------------------------------------------------
INDEX       WORD        FILE COUNT      TOTAL_WORD_COUNT        FILES       WORD_COUNT_FILE
------------------------------------------------------------------------------------------------
0          are         2               2                   f2.txt->f3.txt            1->1
6          good        1               1                   f1.txt                     1
7          hi          3               5                   f1.txt->f2.txt->f3.txt   3->1->1
7          hello       2               2                   f1.txt->f2.txt             1->1
7          how         1               1                   f2.txt                     1
14         ok?         1               1                   f3.txt                     1
24         you         2               2                   f2.txt->f3.txt             1->1
------------------------------------------------------------------------------------------------

SUCCESS : DATABASE IS DISPLAYED SUCCESSFULLY
```

---

**4️⃣ Search Word**

Select:

```text
3
```

Enter:

```text
hi
```

Output:

```text
Enter a word to search: hi

Word hi is present in 3 files
In f1.txt =>3 times
In f2.txt =>1 times
In f3.txt =>1 times
```

This shows that the word **`hi`** occurs:

```text
f1.txt → 3 times
f2.txt → 1 time
f3.txt → 1 time
```

---

**5️⃣ Save Database**

Select:

```text
4
```

Enter the database file name:

```text
database.txt
```

Output:

```text
Enter a file name: database.txt

INFO : DATABASE IS SAVED SUCCESSFULLY
```

The database is stored in the following format:

```text
#0;are;2;2;f2.txt;f3.txt;1;1;#
#6;good;1;1;f1.txt;1;#
#7;hi;3;5;f1.txt;f2.txt;f3.txt;3;1;1;#
#7;hello;2;2;f1.txt;f2.txt;1;1;#
#7;how;1;1;f2.txt;1;#
#14;ok?;1;1;f3.txt;1;#
#24;you;2;2;f2.txt;f3.txt;1;1;#
```

---

**6️⃣ Update Database**

The update operation uses the saved database and can add **new input files** to the existing database.

If there are no new files to update:

```text
Enter the database file name: database.txt

No new files to update
ERROR : DATABASE UPDATE IS FAILED
```

---

## 💡 Key Learning

* Implemented a Hash Table using linked lists
* Learned how inverted indexing works
* Used structures and pointers
* Worked with dynamic memory allocation
* Implemented file handling in C
* Stored and searched words efficiently
* Implemented database creation, saving and updating

---

## 🧪 Result

The **Inverted Search** program successfully creates an inverted database containing:

```text
Word
  ↓
File Count
  ↓
File Names
  ↓
Occurrence Count
```

It supports database creation, display, word searching, saving, and updating using C data structures and file handling.

---

## 👤 Author

**Sk Shabeena**

📧 Email: `skshabeena33@gmail.com`

🔗 LinkedIn: https://www.linkedin.com/in/shaik-shabeena-36a7b9332/

💻 GitHub: https://github.com/shabeena1703
