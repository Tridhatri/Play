// Fun with macros

#include <stdio.h>
#include <math.h>


#define QUADP(a,b,c) ((-b + sqrt(b*b - 4*a*c)) / (2*a))
#define QUADQ(a,b,c) ((-b + sqrt(b*b + 4*a*c)) / (2*a))
#define QUADRATIC(a,b,c) (QUADP(a,b,c)), (QUADQ(a,b,c))



#define PRINT_INT_VAL(x) printf("The value of " #x " is: %d\n", x)


#define STR(x) #x


//Concatenation
#define CAT(a, b) a ## b

//Multiline macros


#define PRINT_NUMS_TO_PRODUCT(a,b) do {\
    int product = (a) * (b); \
    for (int i = 0; i < product ;i++){\
        printf("%d\n", i); \
    }\
} while(0)

#define SIZE 100



#define PRINT_LETTERS_OF_STRING(s)        \
    do {                                  \
        int i = 0;                        \
        while ((s)[i] != '\0') {          \
            printf("%c\n", (s)[i]);         \
            i++;                          \
        }                                 \
    } while (0)



#define PRINT_LETTERS_OF_STRING2(s) \
    do {                            \
        char *pointer = (s)         \
        ;                           \
        while(*p){                  \ 
            putchar(*p);            \
            putchar('\n');          \
            p++;                    \
        }                           \
    }while(0)                       \





//#define X(a,b, ...) (10*(a), 10*(b), __VA_ARGS__)

// So, basically in this macro, the parentheses around the whole thing make it a single expression. 
// The commas inside are comma operators, which means that the entire macro expands to a single value — the last one, which is `__VA_ARGS__`.
// So when you call `X(1,2,3,4)`, it expands to `(10*1, 10*2, 3, 4)`, and the value of this expression is `4`. 
// This is why you only get one argument passed to `printf` instead of three.


//Redefintion (Correct)

#define X(a,b, ...) 10*(a), 10*(b), __VA_ARGS__

int main(void){

    printf("2*x^2 + 10*x + 5 = 0\n");
    printf("The roots are: %f and %f\n", QUADRATIC(2,10,5));



    //printf("X(1,2,3,4) = %d,  %d, %d\n", X(1,2,3,4));
    printf("X(1,2,3,4) = %d,  %d, %d, %d\n", X(1,2,3,4));



    printf("%s\n", STR(3.14159));

    PRINT_INT_VAL(42);



    printf("%f\n", CAT(3.14, 1592));   // 3.141592


    PRINT_NUMS_TO_PRODUCT(2,4);


    PRINT_LETTERS_OF_STRING("hello");
    PRINT_LETTERS_OF_STRING2("tridhatri");

}


#if 0

Let’s rebuild the whole idea from the ground up so the `X` macro makes sense even if you’ve never touched variadic macros or the comma operator before.

---

#  1. What a macro really is

A macro in C is **pure text substitution** done *before* the compiler sees your code.

If you write:

```c
#define DOUBLE(x) (2*(x))
```

then every time the preprocessor sees `DOUBLE(5)` it literally rewrites your code as:

```
(2*(5))
```

No types, no functions — just text replacement.

---

# 2. What is a *variadic macro*?

A variadic macro is one that accepts a variable number of arguments, like `printf`.

```c
#define M(a, ...)   something with a and __VA_ARGS__
```

`__VA_ARGS__` means “all the remaining arguments.”

So:

```
M(1, 2, 3, 4)
```

expands to:

```
something with 1 and 2, 3, 4
```

---

# 3. The comma operator — the part most people don’t know

Inside parentheses, commas can act as the **comma operator**, not as separators.

Example:

```c
int x = (5, 10, 20);
```

This evaluates:

- 5 → ignored  
- 10 → ignored  
- 20 → returned  

So `x` becomes **20**.

The comma operator evaluates each expression left‑to‑right and returns the **last** one.

This is crucial.

---

# 4. Now look at your macro

```c
#define X(a,b, ...) (10*(a), 10*(b), __VA_ARGS__)
```

If you call:

```
X(1,2,3,4)
```

the preprocessor expands it to:

```
(10*(1), 10*(2), 3, 4)
```

Inside parentheses, those commas are **comma operators**, so this is one single expression whose value is **4**.

---

# 5. What happens when you pass it to printf?

You wrote:

```c
printf("X(1,2,3,4) = %d, %d, %d\n", X(1,2,3,4));
```

After macro expansion:

```
printf("X(1,2,3,4) = %d, %d, %d\n",
       (10*(1), 10*(2), 3, 4));
```

Because the whole macro expansion is wrapped in parentheses, it becomes **one argument**.

So the call is effectively:

```
printf("X(1,2,3,4) = %d, %d, %d\n", 4);
```

But the format string expects **three** integers.  
You only supplied **one**.  
The other two come from whatever garbage happens to be on the stack → undefined behavior.

---

# 6. If you want the macro to expand into *multiple arguments*

Remove the parentheses:

```c
#define X(a,b, ...) 10*(a), 10*(b), __VA_ARGS__
```

Now:

```
printf("%d %d %d\n", X(1,2,3));
```

expands to:

```
printf("%d %d %d\n", 10*1, 10*2, 3);
```

which is valid.

---

# 🎯 Summary

| Concept | Meaning |
|--------|---------|
| Macro | Pure text substitution |
| Variadic macro | Uses `__VA_ARGS__` to accept extra arguments |
| Comma operator | `(a, b, c)` evaluates all but returns **c** |
| Your macro | Produces a single expression → one argument to printf |
| Fix | Remove parentheses if you want multiple arguments |

---

If you want, I can also walk through how your `QUADRATIC` macro expands step‑by‑step — that one has its own interesting behavior.

#endif



#if 0


Stringification

##__VA_ARGS__## will evaluate to the string representation of the arguments passed to the macro. 
For example, if you have a macro like this:
#define STRINGIFY(...) #__VA_ARGS__

Then when you call STRINGIFY(Hello, World), it will expand to "Hello, World". 
The # operator is used to convert the arguments into a string literal. 


#endif








#if 0


WHEN TO USE do-while(0)


`do { … } while(0)` looks bizarre the first time you see it, but it’s actually a deliberate C/C++ idiom. It shows up most often in macros, and it solves a few real problems.

## Why people use `do { … } while(0)`

### 1. **To make multi‑statement macros behave like a single statement**
Without this pattern, a macro that expands to multiple statements can break control flow.

Example of a *bad* macro:

```c
#define LOG(x) printf("log: %s\n", x); cleanup();
```

Using it in an `if` statement:

```c
if (error)
    LOG("oops");
else
    handle_ok();
```

After macro expansion:

```c
if (error)
    printf("log: oops\n"); cleanup();
else
    handle_ok();
```

Now `cleanup()` runs **unconditionally**, which is a bug.

### The fix: wrap the macro body

```c
#define LOG(x) do { \
    printf("log: %s\n", x); \
    cleanup(); \
} while(0)
```

Now the macro expands to a single syntactic statement, so the `if/else` works correctly.

---

### 2. **To allow `break` inside the macro**
Because the loop runs exactly once, `break` becomes a clean way to exit early.

```c
#define CHECK(ptr) do { \
    if (!(ptr)) { \
        fprintf(stderr, "null pointer\n"); \
        break; \
    } \
    use(ptr); \
} while(0)
```

This gives you structured early‑exit behavior without `goto`.

---

### 3. **To enforce a trailing semicolon**
The pattern encourages users to write:

```c
LOG("hello");
```

instead of:

```c
LOG("hello")
```

which keeps macro usage consistent with normal function calls.

---

## Why `while(0)` specifically
- The loop runs exactly once.
- The compiler optimizes it away completely.
- It prevents accidental fall‑through or repeated execution.

---

## When *not* to use it
- When writing normal code (not macros), it’s rarely useful.
- When the macro is truly a single expression, you don’t need it.

---

If you want, I can show you some real‑world examples from Linux kernel, embedded code, or Windows headers.

#endif
