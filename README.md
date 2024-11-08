# Compiler Design Lab - CS4171

Welcome to the **Compiler Design Lab** repository for CS4171. This repository is organized for the Compiler Design Lab course, including assignments, reference books, and lecture notes essential for learning compiler construction. Each assignment explores specific topics and practical applications of tools like **Lex** and **Yacc**, guiding you through key concepts in building a compiler.

---

## 📂 Repository Structure

- **[Assignment01](./Assignment01)**: The first assignment folder with relevant files.
- **[Assignment02](./Assignment02)**: The second assignment folder with relevant files.
- **[Assignment03](./Assignment03)**: The third assignment folder with relevant files.
- **[Assignment04](./Assignment04)**: The fourth assignment folder with relevant files.
- **[Assignment05](./Assignment05)**: The fifth assignment folder with relevant files.
- **[Books](./Books)**: Contains reference books for a deeper understanding of compiler design concepts.
- **[Lecture Notes](./Lecture_Notes)**: Includes class notes and supplementary materials for revisiting key topics.

---

## ⚙️ Setup & Compilation Instructions

To compile and execute Lex and Yacc files used in these assignments, follow the steps below.

```bash
# 📋 Prerequisites
# Ensure the following tools are installed on your system:
# Install Yacc and Lex
sudo apt install bison flex
# Install GCC, the standard GNU compiler for C language

# 1. Generate Yacc Output
# Compile the Yacc file (yacc_file.y) to produce y.tab.c and y.tab.h files
yacc -d yacc_file.y

# 2. Generate Lex Output
# Compile the Lex file (lex_file.l) to produce lex.yy.c
lex lex_file.l

# 3. Compile with GCC
# Combine the generated .c files using GCC to create the executable
gcc lex.yy.c y.tab.c -o output

# 4. Run the Executable
# Execute the compiled program with a test file (e.g., test.c)
./output test.c
