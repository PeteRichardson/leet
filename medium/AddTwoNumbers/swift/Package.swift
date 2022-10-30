// swift-tools-version: 5.7
import PackageDescription

let package = Package(
    name: "AddTwoNumbers",
    platforms: [
        .macOS(.v13)
    ],
    products: [
        .executable(name: "AddTwoNumbers", targets: ["AddTwoNumbers"])
    ],
    targets: [
        .target(
            name: "AddTwoNumbers",
            path: "."
        )
    ]
)