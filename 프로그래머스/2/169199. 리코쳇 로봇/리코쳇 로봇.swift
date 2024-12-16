import Foundation

var dx = [1,0,-1,0]
var dy = [0,1,0,-1]

func solution(_ board:[String]) -> Int {
    let board = board.map { $0.map { String($0) }}
    var queue: [(Int, Int)] = []
    var cntMap: [[Int]] = Array(repeating: Array(repeating: 987654321, count: board[0].count), count: board.count)
    
    for i in 0..<board.count {
        if !queue.isEmpty { break }
        for j in 0..<board[0].count {
            if board[i][j] == "R" {
                queue.append((i, j))
                cntMap[i][j] = 0
                break
            }
        }
    }
    
    while(!queue.isEmpty) {
        var position = queue.removeFirst()
        var y = position.0
        var x = position.1
        
        if board[y][x] == "G" {
            return cntMap[y][x]
        }
        
        for i in 0..<4 {
            var ny = y
            var nx = x
            
            while(true) {
                ny += dy[i]
                nx += dx[i]
                
                if ny < 0 || ny >= board.count || nx < 0 || nx >= board[0].count {
                    ny -= dy[i]
                    nx -= dx[i]
                    break
                }
                
                if board[ny][nx] == "D" {
                    ny -= dy[i]
                    nx -= dx[i]
                    break
                }
            }
            
            if cntMap[ny][nx] > cntMap[y][x] + 1 {
                cntMap[ny][nx] = cntMap[y][x] + 1
                queue.append((ny, nx))
            }
        }
    }
    
    return -1
}