Push_swap - Sorting with Stacks
📝 Project Description
Push_swap is a sorting algorithm project that involves manipulating two stacks (a and b) using a limited set of operations. The goal is to sort a list of unique integers into ascending order using the fewest moves possible.

This project enhances algorithmic thinking and data structure manipulation while optimizing performance.

🧮 Features
✅ Efficient sorting with minimal operations
✅ Implemented stack-based sorting algorithms
✅ Custom instruction set for sorting
✅ Error handling for invalid input
✅ Supports large data sets with optimized sorting strategies
✅ Bonus: Checker program to verify sorting correctness

🖥️ Installation & Usage
1️⃣ Clone the Repository
sh
Copier
Modifier
git clone https://github.com/radouani-md/push_swap.git
cd push_swap
2️⃣ Compile the Program
sh
Copier
Modifier
make
For the bonus checker program, use:

sh
Copier
Modifier
make bonus
3️⃣ Run Push_swap
Pass a sequence of integers as arguments:

sh
Copier
Modifier
./push_swap 4 67 3 87 23
It will output a sequence of operations to sort the stack.

✅ Verify Sorting with Checker
sh
Copier
Modifier
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK → Numbers are sorted correctly.
KO → Sorting is incorrect.
🔄 Allowed Operations
Operation	Description
sa	Swap top two elements of stack a
sb	Swap top two elements of stack b
ss	Swap a and b simultaneously
pa	Push the top element from b to a
pb	Push the top element from a to b
ra	Rotate a (shift all elements up)
rb	Rotate b (shift all elements up)
rr	Rotate both a and b
rra	Reverse rotate a (shift all elements down)
rrb	Reverse rotate b (shift all elements down)
rrr	Reverse rotate both a and b
📊 Benchmark Requirements
To pass the evaluation, the program must efficiently sort:
✔ 100 random numbers in ≤700 operations
✔ 500 random numbers in ≤5500 operations

The fewer moves, the better the optimization! 🚀

⚠️ Errors & Debugging
If an error occurs, the program displays "Error" and exits safely.
Common errors include:
❌ Non-integer inputs
❌ Numbers exceeding integer limits
❌ Duplicate numbers
❌ Invalid formatting

🚀 Bonus Features
🌟 Checker program to validate sorting correctness
🌟 Advanced sorting optimizations for large numbers
🌟 Efficient move reduction techniques

🛠️ Requirements
✔ GNU/Linux or macOS
✔ Make & GCC
✔ No external libraries (except ft_printf)

📜 License
This project follows the 42 School Norms and is intended for educational purposes.

🙌 Acknowledgments
Special thanks to 42 Network for this challenge and to peers who contributed to optimizing sorting techniques.

"Sorting numbers has never been this fun!" 🎯✨
