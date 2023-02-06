import Foundation

let dx = [1,0,-1,0]
let dy = [0,1,0,-1]
var visited: [[Bool]] = Array(repeating: Array(repeating: false, count: myMaps[0].count), count: myMaps.count)
var myMaps: [[String.Element]] = []

func dfs(y: Int, x: Int) -> Int {
    var cur = Int(String(myMaps[y][x]))!
    
    if visited[y][x] { return 0}
    visited[y][x] = true
    
    for i in 0...3 {
        let ny = y + dy[i]
        let nx = x + dx[i]
        
        if ny >= 0 && ny < myMaps.count && nx >= 0 && nx < myMaps[0].count && visited[ny][nx] == false && myMaps[ny][nx] != "X" {
            cur += dfs(y: ny, x: nx)
        }
    }
    
    return cur
}

func solution(_ maps:[String]) -> [Int] {
    myMaps = maps.map { Array($0) }
    var result: [Int] = []
for (idx, i) in maps.enumerated() {
    for (idxx, j) in i.enumerated() {
        if j != "X" {
            let sum = dfs(y: idx, x: idxx)
            
            if sum != 0 { result.append(sum) }
        }
    }
}

if result.isEmpty {
    result = [-1]
} else {
    result.sort()
}
    return result
}