import Foundation

var input = readLine()!.split(separator: " ").map { Int($0)! }
let n = input[0], m = input[1]

for _ in 1...m {
    for _ in 1...n {
        print("*",terminator: "")
    }
    print("")
}