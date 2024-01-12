# Answer for arithmetic intensities:

* First kernel:
  1. Three flops including two summations and one multiplication.
  2. Three reads including `A[j][i]`, `B[i]`, and `Y[j]`, and one write `Y[j]`
  3. Arithmetic Intensity = $\frac{3}{4 \times 8}$
* Second kernel:
  1. Two flops including one summation and one multiplication.
  2. One read which includes `A[i]`
  3. `s` is a constant and stays in register. Therefore its read and write assumes to happen instantly.
  4. Arithmetic Intensity = $\frac{2}{1 \times 8}$
* Third kernel:
  1. Two flops including one summation and one multiplication.
  2. Two reads including `A[i]` and `B[i]`.
  3. `s` is a constant and stays in register. Therefore its read and write assumes to happen instantly.
  4. Arithmetic Intensity = $\frac{2}{2 \times 8}$
* Fourth kernel:
  1. Two flops including one summation and one multiplication.
  2. Two reads including `A[i]` and `B[i]`, and one write including `Y[i]`.
  3. Arithmetic Intensity = $\frac{2}{3 \times 8}$