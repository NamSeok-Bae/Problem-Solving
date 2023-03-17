import Foundation

func solution(_ wallpaper:[String]) -> [Int] {
    var left = 987654321
    var right = -1
    var up = 987654321
    var down = -1

    var points = Array(repeating: [Int](), count: wallpaper.count)

    for (idx, i) in wallpaper.enumerated() {
        for (jdx, j) in i.map({ String($0) }).enumerated() {
            if j == "#" {
                up = min(idx, up)
                left = min(jdx, left)
                down = max(idx, down)
                right = max(jdx, right)
            }
        }
    }
    return [up, left, down + 1, right + 1]
}