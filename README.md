# C++ Preprocessor - Cross Platform Debugger
You’re developing a cross-platform tool for developers who need to debug and profile their C++ programs efficiently. Whether it’s Windows, Linux, or macOS, this utility adapts seamlessly.

By the end of this project, you’ll have a system that logs compile-time information, detects the operating system, measures how long your functions take, and indicates whether you’re in debug mode, all utilizing modern, clean C++ code.

Let’s build it step by step and make your compiler more efficient!

## Setting Up the Platform & Building Context

1. Most compilers define special macros based on the operating system. For Windows, `_WIN32` is automatically defined.

   In `values.hpp`,

- Check if the code is being compiled on a Windows machine by using the `_WIN32` macro.
- If it is, define a new macro named `PLATFORM` and assign it the value `"Windows"`.

2. Let’s expand platform detection to support Linux and macOS too!

   In `values.hpp`, add checks for both `Linux` and `macOS`.
3. Use the `__linux__` macro to check if the code is running on `Linux`, and define `PLATFORM` as `"Linux"` if it is.
4. Similarly, use the `__APPLE__` macro to detect `macOS` and set `PLATFORM` to `"macOS"`.
5. Not every system may match the platforms you’ve checked.

   After checking for all supported platforms, add one final condition to handle any system that doesn’t match. If none of your checks apply:

   1. Create a macro called `PLATFORM` with the value `"Unsupported platform"`.
   2. Trigger a compile-time error with the message:

```
This platform is not supported.
```

4. Let’s simplify time-related code by creating two helpful macros.

   The `<chrono>` library provides tools to work with time, but expressions like `chrono::high_resolution_clock::now()` can be long and repetitive.

- Define a macro `TIME_POINT` for `chrono::high_resolution_clock::time_point`.
- Define another macro `NOW` for `chrono::high_resolution_clock::now()`.

5. Let’s create a macro to easily measure how much time has passed between two points.
   Define a reusable macro named `DURATION(start, end)` that takes two parameters (`start` and `end`) and returns the time difference between them in microseconds.

## Building the Debug Logger

6. Let’s make logging messages more readable and consistent.

Open `Logger.cpp` and locate the `logLocation()` function. Inside this function, create a print statement that formats the log message like this:

```
[LOG] filename:line (function) - message Copy to Clipboard
```

Use the parameters passed into `logLocation()` (`file`, `line`, `function`, `message`) to replace `filename`, `line`, `function`, and `message` in the format above.

7. At the bottom of `Logger.hpp`, define a macro called `LOG_LOCATION(msg)` that automatically calls `Logger::logLocation()` and fills in the file, line, and function name.

## Implementing Execution Timing

8. To measure how long things take, we first need to mark the start time, let’s set that up now.

Inside the `Logger` class in `Logger.hpp`, add a static variable named `startTime` under the `private` section.

Use the `TIME_POINT` macro as its type.

9. You previously declared `startTime` as a static variable in the `Logger` class.

Now, you need to define it in `Logger.cpp` so it is actually allocated in memory and can store a value when the timer runs.

10. Assign the current time to `startTime` using the `NOW` macro you defined earlier.
11. Inside `Logger.cpp`, start writing the `stopTimer()` function. Inside the `stopTimer()` function, declare a variable called `endTime` and assign it the current time.
12. In the `stopTimer()` function in `Logger.cpp`, calculate how much time has passed since `startTime`. Use the `DURATION` macro you created earlier and store the result in a variable named `duration`.
13. At the end of the `stopTimer()` function in `Logger.cpp`, print the timer result in the following format:

```
[TIMER] (functionName) - Duration: XYZ µs
```

14. In `Logger.hpp`, define two macros:

- `START_TIMER()`: This macro should call the `Logger` method that starts the timer.
- `STOP_TIMER()`: This macro should call the `Logger` method that stops the timer, automatically passing the name of the current function to it.

## Printing Build Metadata

15. In the `Logger.cpp` file, continue writing the `printCompileInfo()` function.

Inside the function, print the date and time when the program was compiled. This helps track when the current build was created.

Your output should follow this format:

```
Date: Apr 30 2025   
Time: 14:52:19
```

16. To make your code more informative, print the compiler name and version used to build the project.

Inside the `printCompileInfo()` function, use conditional compilation to detect the compiler. For the major compilers, display messages like:

- GCC → `Compiler: GCC <major>.<minor>`
- Clang → `Compiler: Clang <major>.<minor>`
- MSVC → `Compiler: MSVC <version>`

Use the appropriate predefined macros for each compiler to obtain the version number.

17. Inside the `printCompileInfo()` function, print the platform name using the `PLATFORM` macro defined in `values.hpp`.
18. In `Logger.hpp`, define a macro named `COMPILE_INFO()` that calls the `printCompileInfo()` method from the `Logger` class.

## Running and Verifying the System

19. Enable debug mode so that debug logs, compile info, and timers are visible in your program’s output. You’ll do this by defining the `DEBUG_MODE` macro directly in your `values.hpp` file.
20. In the `main()` function in main.cpp, check if debug mode is enabled. If it is, call the `COMPILE_INFO()` macro at the top of the function to print compile information.
21. When debugging or analyzing program execution, it’s helpful to know which functions are running. Adding log messages at the start of functions makes it easier to follow the program flow.

In `Algorithms.cpp`, at the top of each loop function, add a call to the `LOG_LOCATION()` macro to make it easier to track program execution.

- In `singleLoop()`, log `"Running single loop"`
- In `doubleLoop()`, log `"Running double loop"`
- In `tripleLoop()`, log `"Running triple loop"`

22. Surround the `for loops` present inside the `singleLoop()`, `doubleLoop()`, and `tripleLoop()` methods with `START_TIMER()` and `STOP_TIMER()` to measure their durations.
23. Congratulations! You’ve successfully completed all the tasks in this project.

Return to `main.cpp` and press **RUN** to check if everything is functioning properly.

Once your program runs successfully, consider exploring additional enhancements to deepen your understanding and make your code even more robust:

- **Add more logging**: Insert log statements in other functions, or experiment with different log levels (`INFO`, `WARNING`, `ERROR`).
- **Measure additional timers**: Track execution time for nested loops or critical code sections.
- **Introduce conditional logging**: Enable or disable logs for specific modules or functions.
- **Enhance compile info**: Include more environment details like operating system, platform architecture, or build date.
- **Create reusable utility macros**: For common tasks like printing separators, formatting output, or calculating values.
- **Customize output**: Print logs to a file or experiment with colored output for different log levels.
