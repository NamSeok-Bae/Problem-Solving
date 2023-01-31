//
//  main.swift
//  알고리즘
//
//  Created by 배남석 on 2023/01/30.
//

import Foundation

// 2580_스도쿠

struct Point {
    var x: Int
    var y: Int
    
    init(x: Int, y: Int) {
        self.x = x
        self.y = y
    }
}

var board = Array(repeating: Array(repeating: 0, count: 9), count: 9)
var row = Array(repeating: Array(repeating: false, count: 10), count: 9)
var column = Array(repeating: Array(repeating: false, count: 10), count: 9)
var around = Array(repeating: Array(repeating: Array(repeating: false, count: 10), count: 3), count: 3)
var zeroPoints = [Point]()
var zeroCount = 0

for i in 0...8 {
    let input = readLine()!.split(separator: " ").map { Int(String($0))! }
    for j in 0...8 {
        board[i][j] = input[j]
        if input[j] == 0 {
            zeroPoints.append(Point(x: j, y: i))
            zeroCount += 1
        }
    }
}

for i in 0...8 {
    for j in 0...8 {
        row[i][board[i][j]] = true
        column[i][board[j][i]] = true
        around[i/3][j/3][board[i][j]] = true
    }
}

var foundResult = false
func solve(cnt: Int) {
    if cnt == zeroCount {
        for i in board {
            for j in i {
                print(j, terminator: " ")
            }
            print("")
        }
        exit(0)
    } else {
        let point = zeroPoints[cnt]
        for i in 1...9 {
            if !row[point.y][i] && !column[point.x][i] && !around[point.y/3][point.x/3][i] {
                board[point.y][point.x] = i
                row[point.y][i] = true
                column[point.x][i] = true
                around[point.y/3][point.x/3][i] = true
                solve(cnt: cnt + 1)
                board[point.y][point.x] = 0
                row[point.y][i] = false
                column[point.x][i] = false
                around[point.y/3][point.x/3][i] = false
            }
        }
    }
}
solve(cnt: 0)
