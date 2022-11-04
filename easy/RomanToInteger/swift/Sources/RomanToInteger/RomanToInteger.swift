class Solution {
    let values: [Character : Int] = [
        "I" : 1,
        "V" : 5,
        "X" : 10,
        "L" : 50,
        "C" : 100,
        "D" : 500,
        "M" : 1000,
    ]

    func romanToInt(_ s: String) -> Int {
        var result: Int = 0
        var prev : Character = " ";
        for c: Character in s { 
            switch c {
                case "I":
                    result += 1
                case "V":
                    result += (prev == "I") ? 3 : 5
                case "X":
                    result += (prev == "I") ? 8 : 10
                case "L":
                    result += (prev == "X") ? 30 : 50
                case "C":
                    result += (prev == "X") ? 80 : 100
                case "D":
                    result += (prev == "C") ? 300 : 500
                case "M":
                    result += (prev == "C") ? 800 : 1000
                default:
                    return -1
            }
            prev = c
        }
        return result
    }
}

@main
public struct RomanToInteger {
    public static func main() {
        let sol : Solution = Solution()
        let roman : String = "III"
        let arabic : Int = sol.romanToInt(roman)
        print("\(roman) = \(arabic)")
    }
}
