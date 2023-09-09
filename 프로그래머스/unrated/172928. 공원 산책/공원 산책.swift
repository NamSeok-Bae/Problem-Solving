import Foundation

func solution(_ park:[String], _ routes:[String]) -> [Int] {
    var parkMap = Array(repeating: [String](), count: park.count)
    var curX: Int = 0
    var curY: Int = 0

    park.enumerated().forEach { (idx, i) in
        i.map { String($0) }.enumerated().forEach { (jdx, j) in
            parkMap[idx].append(j)

            if j == "S" {
                curX = jdx
                curY = idx
            }
        }
    }

    routes.forEach {
        let route = $0.split(separator: " ")
        let direct = route[0]
        let number = Int(route[1])!

        if direct == "E" {
            if curX + number >= parkMap[0].count {
                return
            }

            for i in stride(from: curX, through: curX + number, by: 1) {
                if parkMap[curY][i] == "X" {
                    return
                }
            }
            curX = curX + number
        } else if direct == "S" {
            if curY + number >= parkMap.count {
                return
            }

            for i in stride(from: curY, through: curY + number, by: 1) {
                if parkMap[i][curX] == "X" {
                    return
                }
            }
            curY = curY + number
        } else if direct == "W" {
            if curX - number < 0 {
                return
            }

            for i in stride(from: curX, through: curX - number, by: -1) {
                if parkMap[curY][i] == "X" {
                    return
                }
            }
            curX = curX - number
        } else {
            if curY - number < 0 {
                return
            }

            for i in stride(from: curY, through: curY - number, by: -1) {
                if parkMap[i][curX] == "X" {
                    return
                }
            }
            curY = curY - number
        }
    }

    
    return [curY, curX]
}