import XCTest
@testable import RomanToInteger

final class RomanToIntegerTests: XCTestCase {

    func testSimple() throws {
        XCTAssertEqual(Solution().romanToInt("I"), 1)
        XCTAssertEqual(Solution().romanToInt("III"), 3)
        XCTAssertEqual(Solution().romanToInt("XV"), 15)
        XCTAssertEqual(Solution().romanToInt("MDCLXVI"), 1666)
    }

    func testSubtractions() throws {
        XCTAssertEqual(Solution().romanToInt("IV"), 4)
        XCTAssertEqual(Solution().romanToInt("IX"), 9)
        XCTAssertEqual(Solution().romanToInt("XL"), 40)
        XCTAssertEqual(Solution().romanToInt("XC"), 90)
        XCTAssertEqual(Solution().romanToInt("CD"), 400)
        XCTAssertEqual(Solution().romanToInt("CM"), 900)
    }

    func testBoundaries() throws {
        XCTAssertEqual(Solution().romanToInt("MMMCMXCIX"), 3999)
    }
}
