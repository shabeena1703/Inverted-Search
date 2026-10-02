# 🔎 Inverted Search

> A C-based file indexing system that creates a searchable database from multiple text files using Hash Tables and Linked Lists.

---

## 📝 About the Project

The **Inverted Search** project indexes words from multiple `.txt` files and stores where each word occurs.

Instead of searching every file one by one, the project creates an **inverted index**:

```text
Normal Search
─────────────
f1.txt → hi, hello, good
f2.txt → hi, how, are
f3.txt → hi, are, you


Inverted Search
───────────────
hi
 ├── f1.txt → 3 times
 ├── f2.txt → 1 time
 └── f3.txt → 1 time
```

So, searching for a word directly gives the **files containing it and its occurrence count**.

---

## ✨ Features

* 📂 **File Validation** – validates input files and avoids duplicates
* 🗃️ **Create Database** – builds the inverted index from multiple files
* 📊 **Display Database** – displays indexed words, files and counts
* 🔍 **Search Word** – finds a word and shows its file-wise frequency
* 💾 **Save Database** – stores the index in a database file
* 🔄 **Update Database** – loads a saved database and adds new files

---

## 🧠 How It Works

The project combines a **Hash Table + Linked Lists**:

```text
                    HASH TABLE
                        │
        ┌───────────────┼───────────────┐
        ↓               ↓               ↓
     Index 0          Index 7         Index 14
        │               │               │
       are              hi              ok?
        │               │
     ┌──┴──┐       ┌────┼────┐
     ↓     ↓       ↓    ↓    ↓
   f2.txt f3.txt f1.txt f2.txt f3.txt
     1     1         3    1    1
```

**Each word stores:**

```text
Word
 ↓
File Count
 ↓
Total Word Count
 ↓
File Name + Word Count
```

---

## 🛠️ Technologies & Concepts

| Category        | Used                                  |
| --------------- | ------------------------------------- |
| Language        | C                                     |
| Data Structures | Hash Table, Linked Lists              |
| Concepts        | Pointers, Structures, Dynamic Memory  |
| File Handling   | `fopen()`, `fgetc()`, file operations |
| Environment     | Linux / WSL                           |
| Compiler        | GCC                                   |

---

## 📁 Project Structure

```text
shabeena_inverted_search/
│
├── main.c
├── main.h
├── validations.c
├── create_database.c
├── display_database.c
├── search_database.c
├── save_database.c
├── update_database.c
│
├── f1.txt
├── f2.txt
├── f3.txt
└── README.md
```

---

## 🔄 Program Flow

```text
        Multiple .txt Files
                │
                ▼
        ┌─────────────────┐
        │ File Validation │
        └────────┬────────┘
                 ▼
        ┌─────────────────┐
        │ Create Database │
        └────────┬────────┘
                 ▼
        ┌─────────────────┐
        │ Inverted Index  │
        └────────┬────────┘
                 │
       ┌─────────┼─────────┐
       ▼         ▼         ▼
    Display    Search     Save
                           │
                           ▼
                         Update
```

---

## 📊 Sample Output

**Database**

```text
INDEX   WORD     FILE COUNT   TOTAL COUNT
-----------------------------------------
0       are      2            2
6       good     1            1
7       hi       3            5
7       hello    2            2
7       how      1            1
14      ok?      1            1
24      you      2            2
```

**Search**

```text
Enter a word to search: hi

Word hi is present in 3 files
In f1.txt => 3 times
In f2.txt => 1 times
In f3.txt => 1 times
```

---

## 🚀 How to Run

** 1️⃣ Compile**

```bash
gcc *.c
```

**2️⃣ Run with Text Files**

```bash
./a.out f1.txt f2.txt f3.txt
```

**3️⃣ Select an Operation**

```text
1. Create Database
2. Display Database
3. Search Word
4. Save Database
5. Update Database
6. Exit
```

**💾 Save & Update**

Save the database:

```text
4
Enter a file name: database.txt
```

To update the database, provide a **new `.txt` file that was not already indexed**, then load the saved database:

```text
5
Enter the database file name: database.txt
```

This allows the existing database to be extended with information from new files.

---

## 💡 Key Learning

Through this project, I gained practical experience in:

Hashing → Linked Lists → File Handling → Dynamic Memory → Searching → Database Management

---

## 🧪 Result

Successfully developed an **Inverted Search Database in C** that indexes words from multiple files and provides efficient **search, display, save, and update operations**.

---

## 👤 Author

**Sk Shabeena**

📧 **Email:** [skshabeena33@gmail.com](mailto:skshabeena33@gmail.com)

🔗 **LinkedIn:** [Shaik Shabeena](https://www.linkedin.com/in/shaik-shabeena-36a7b9332/)


---
