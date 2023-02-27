import Foundation

func checkLine(positions: [(Int, Int)]) -> Bool {
    //가로, 세로, 대각선
    let row = [[(0,0), (0,1), (0,2)],
               [(1,0), (1,1), (1,2)],
               [(2,0), (2,1), (2,2)]]
    let column = [[(0,0), (1,0), (2,0)],
                  [(0,1), (1,1), (2,1)],
                  [(0,2), (1,2), (2,2)]]
    let diagonal = [[(0,0), (1,1), (2,2)],
                    [(0,2), (1,1),(2,0)]]
    
    var isLine = false
    for i in row {
        if positions.filter { element in i.contains { $0 == element } }.count == 3 {
            isLine = true
        }
    }
    
    for i in column {
        if positions.filter { element in i.contains { $0 == element } }.count == 3 {
            isLine = true
        }
    }
    
    for i in diagonal {
        if positions.filter { element in i.contains { $0 == element } }.count == 3 {
            isLine = true
        }
    }
    
    return isLine
}

func solution(_ board:[String]) -> Int {
    let temp = board.map { $0.map { String($0) } }

    var Oposition = [(Int, Int)]()
    var Xposition = [(Int, Int)]()

    for (idx, i) in temp.enumerated() {
        for (jdx, j) in i.enumerated() {
            if j == "O" {
                Oposition.append((idx, jdx))
            } else if j == "X" {
                Xposition.append((idx, jdx))
            }
        }
    }

    if Oposition.count < Xposition.count {
        return 0
    } else if Oposition.count == Xposition.count {
        if checkLine(positions: Oposition) {
            return 0
        } else {
            return 1
        }
    } else {
        if Oposition.count - Xposition.count > 1 {
            return 0
        }
        
        if checkLine(positions: Xposition) {
            return 0
        } else {
            return 1
        }
    }
}