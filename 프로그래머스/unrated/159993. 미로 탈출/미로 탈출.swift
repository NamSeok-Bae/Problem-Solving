import Foundation

let dx = [1,0,-1,0]
let dy = [0,1,0,-1]

func BFS(startPoint: (Int, Int), endPoint: (Int, Int), maps: [[String]]) -> Int {
    var queue = [startPoint]
    let tempMap = maps
    var numberMap = Array(repeating: Array(repeating: 0, count: tempMap[0].count), count: tempMap.count)
    while !queue.isEmpty {
        let point = queue.removeFirst()
        let x = point.1
        let y = point.0
        
        if point == endPoint {
            return numberMap[y][x]
        }
        
        for i in 0...3 {
            let ny = y + dy[i]
            let nx = x + dx[i]
            
            if ny >= 0 && ny < tempMap.count && nx >= 0 && nx < tempMap[0].count && tempMap[ny][nx] != "X" && numberMap[ny][nx] == 0 {
                numberMap[ny][nx] = numberMap[y][x] + 1
                queue.append((ny,nx))
            }
        }
    }
    return -1
}

func solution(_ maps:[String]) -> Int {
    var tempMap = maps.map { $0.map { String($0) } }
    var startPoint = (0,0)
    var leverPoint = (0,0)
    var exitPoint = (0,0)

    for (idx, i) in tempMap.enumerated() {
        for (jdx, j) in i.enumerated() {
            if j == "S" {
                startPoint = (idx,jdx)
            } else if j == "L" {
                leverPoint = (idx,jdx)
            } else if j == "E" {
                exitPoint = (idx,jdx)
            }
        }
    }
    var first = BFS(startPoint: startPoint, endPoint: leverPoint, maps: tempMap)
    var second = BFS(startPoint: leverPoint, endPoint: exitPoint, maps: tempMap)

    return first == -1 || second == -1 ? -1 : first + second
}