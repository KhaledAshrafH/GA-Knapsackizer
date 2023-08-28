# Genetic Algorithm Knapsackizer

This repository contains a C++ program that solves the Knapsack Problem using a Genetic Algorithm. The Knapsack Problem is a classic optimization problem where we aim to maximize the total value of items to be packed in a knapsack, given the knapsack's weight capacity and a set of items with their respective weights and values.

## Problem Description

The program takes an input file as input, which should be in the following format:

```
Number of test cases
Size of the knapsack
Number of items
Weight and value of each item
```

The program supports multiple test cases, and for each test case, it generates a solution using the Genetic Algorithm.

## Genetic Algorithm Implementation

The Genetic Algorithm implemented in this program follows these key steps:

1. **Chromosome Representation**: The algorithm uses a binary, one-dimensional chromosome to represent the solution. Each gene in the chromosome represents whether an item is selected (1) or not (0) to be included in the knapsack.

2. **Population Initialization**: The initial population of solutions is created using a user-defined population size. Each solution is randomly generated, ensuring that it satisfies the constraints of the problem.

3. **Individual Evaluation**: The fitness of each solution in the population is evaluated based on its total value. The fitness function calculates the total value of the selected items in the knapsack.

4. **Selection**: The selection process, known as rank selection, chooses the parent solutions with a higher probability of selection based on their rank in the population. Solutions with higher fitness have a better chance of being selected for reproduction.

5. **Crossover**: The crossover operation combines genetic material from two parent solutions to create offspring solutions. The program uses a one-point crossover technique to create new solutions.

6. **Mutation**: The mutation operation introduces random changes in the offspring solutions to maintain diversity in the population. The mutation rate is a user-defined parameter that determines the probability of a gene being flipped.

7. **Reproduction**: The new offspring solutions replace the least fit solutions in the population, ensuring the population size remains constant.

8. **Termination**: The algorithm continues iterating through the steps mentioned above for a specified number of generations or until a termination condition is met. In this program, the termination condition is the completion of a fixed number of iterations (e.g., `numOfIterations`).

## Usage

To use this program, follow the steps below:

1. Prepare an input file in the specified format with the test cases and their details.

2. Compile the C++ program, ensuring that the necessary dependencies are installed.

3. Run the compiled program, providing the input file as input.

4. The program will output the results for each test case, including the selected items, their weights, and values.

## Parameters

The Genetic Algorithm implemented in this program uses the following parameters:

- `populationSize`: The size of the population (e.g., `1374`).
- `numOfIterations`: The number of generations (e.g., `74`).
- `Pc`: The crossover rate, determining the probability of performing crossover (e.g., `0.5`).
- `Pm`: The mutation rate, determining the probability of introducing random changes (e.g., `0.05`).
- `cnt`: A counter variable (e.g., `0`, for tracking iterations or other purposes).

You can modify these parameters in the source code to customize the behavior of the algorithm.

## Example

Consider the following input:

```
2

14
5
4 1
7 7
1 22
3 23
3 6

28
5
10 27
9 27
8 12
8 28
3 23
```

The program will produce the following output:

```
Testcase 1:
Number of selected items: 4
Total Value: 58
Item 2: Weight = 7, Value = 7
Item 3: Weight = 1, Value = 22
Item 4: Weight = 3, Value = 23
Item 5: Weight = 3, Value = 6

Testcase 2:
Number of selected items: 4
Total Value: 90
Item 2: Weight = 9, Value = 27
Item 3: Weight = 8, Value = 12
Item 4: Weight = 8, Value = 28
Item 5: Weight = 3, Value = 23
```

In the first test case, the knapsack has a capacity of 14, and there are 5 items available. The algorithm selects 4 items with a total value of 58. The selected items are item 2, 3, 4, and 5, with their respective weights and values provided.

In the secondtest case, the knapsack has a capacity of 28, and there are 5 items available. The algorithm selects 4 items with a total value of 90. The selected items are item 2, 3, 4, and 5, with their respective weights and values provided.

## Conclusion

The Knapsack Problem Genetic Algorithm implemented in this program provides a solution to the optimization problem of maximizing the total value of items in a knapsack. By using a genetic algorithm approach, it explores different combinations of items and evolves a population of solutions over generations to find an optimal or near-optimal solution.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvement, please open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE.md).
