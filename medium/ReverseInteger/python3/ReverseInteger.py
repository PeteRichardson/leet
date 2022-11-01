
min_result = -214748365 # (-2**31)    //10
max_result = 214748365  # ( 2**31 - 1)//10
def reverse(x: int) -> int:
    sign = 1
    if x < 0:
        sign = -1
        x = abs(x)
    
    result = 0
    while x > 0:
        last_digit = x % 10
        # check if it's _about to be_ out of range if we continue this loop
        if result >= max_result or result <= min_result:
            #print(f"#\tGOING TO BE OUT OF RANGE: x =={x}, result=={result}")
            return 0
        result = result * 10 + last_digit
        #print(f"\t{result}")
        x = x // 10
    return sign * result

def test(x : int, answer : int):
    print(f"# test: reverse({x}) == {answer}?  ")
    a = reverse(x)
    if (a == answer):
        print(f"\tPASS   (reverse(x) == {a} == {answer})")
    else:
        print(f"\tFAIL!!  (reverse(x) == {a} != {answer})")
    
if __name__ == "__main__":
    test(32,23)
    test(-32, -23)
    test(12345, 54321)
    test(-12345, -54321)
    test(120, 21)
    test(2147447412, 2147447412)  
    test(2147483647, 0)             # reverse is out of bounds 
    test(2147483641, 1463847412)    # reverse is OK 
    test(-2147483648, 0)            # reverse is out of bounds
    test(-2147483641, -1463847412)  # reverse is OK
    test(1563847412, 0)