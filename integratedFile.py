import subprocess
import numpy as np
import matplotlib.pyplot as plt

def main():
    iterations = 10
    n_array = np.array([25*i for i in range(1, 11)] + [50*i for i in range(6, 11)] + [100*i for i in range(6, 11)] + [200*i for i in range(6, 11)], dtype=np.int64)
    # n_array = np.array([25*i for i in range(1, 11)], dtype=np.int64)

    rt_dict = {}
    meanRunTimeArray = []

    # Compile the C++ program first (adjust the command if needed for your compiler)
    subprocess.run(["g++", "-o", "project_integrated.exe", "project1_integrated.cpp"])

    for n in n_array:
        # Run the C++ program with the current 'n' and capture the output
        result = subprocess.run(["project_integrated.exe", str(n), str(iterations)], capture_output=True, text=True, shell=True)
        output = result.stdout
        error = result.stderr

        if error:
            print(f"Error for n={n}: {error}")
            continue

        print(f"Output for n={n}: '{output}'\n")  # Print output for debugging

        runtimes = [float(line) for line in output.strip().split('\n') if line]
        rt_dict[n] = runtimes

        # Calculate the average runtime for each 'n'
        meanRunTime = np.mean(rt_dict[n])
        meanRunTimeArray.append(meanRunTime)
        print(f"Average time for n={n}: '{meanRunTime}\n")
        
        if not rt_dict:
            print("No runtime data collected. Exiting.")
            exit()

        # Ensure avg_rt_array is not empty before proceeding
        if not meanRunTimeArray:
            print("No average runtime data collected. Exiting.")
            exit()

            # Initialize an array to store the number of floating point operations.
    flop_array = (n_array**2) * (2*n_array - 1)

    # Calculate the performance in (Gflop/s)
    performance = (flop_array / 1e9) / np.array(meanRunTimeArray)

    ncores = 20  # number of cores
    clkspeed = 2.4  # 3.4 GHz
    fpus = 2  # FPUs/core

    peakp = ncores * clkspeed * fpus

    print("Theoretical Peak Performance:", peakp, "GFlop/s")

    plt.figure()
    plt.plot(n_array, performance, '--d')
    plt.xlabel('Array Size (N)')
    plt.ylabel('GFlop/s')
    # plt.axhline(y=peakp, linestyle='--', color='red', label='Peak Performance')
    plt.savefig('HPCCEmpiricalResults.png')
    # plt.show()

    for n, meanRunTime in zip(n_array, meanRunTimeArray):
        print(f"Mean Runtime for n = {n}: {np.round(meanRunTime,3)} s")

    print("\n")

    for n, i in zip(n_array, performance):
        print(f"Mean Performance for n = {n}: {np.round(i,3)} GFlops/s")

    print("\n")

    idx100 = np.argwhere(n_array == 100)[0][0]
    meanRunTime100 = meanRunTimeArray[idx100]
    performance100 = performance[idx100]
    print("Mean Runtime for n = 100: ", meanRunTime100)
    print("Mean Performance for n = 100: ", performance100)


if __name__ == "__main__":
    main()