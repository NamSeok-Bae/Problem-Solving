//
//  main.swift
//  알고리즘
//
//  Created by 배남석 on 2022/09/14.
//

import Foundation

// 1717_집합의표현

func findParent(_ x: Int) -> Int {
    if x != parent[x] {
        parent[x] = findParent(parent[x])
    }
    return parent[x]
}

func union(_ a: Int, _ b: Int) {
    let a = findParent(a)
    let b = findParent(b)

    if a >= b {
        parent[a] = b
    } else {
        parent[b] = a
    }
}

var input = readLine()!.split(separator: " ").map {
    Int(String($0))!
}

var n = input[0]
var m = input[1]

var parent = Array(0...n)

for _ in 0..<m {
    input = readLine()!.split(separator: " ").map { Int(String($0))! }

    let a = input[1]
    let b = input[2]

    if input[0] == 0 {
        union(a, b)
    } else {
        if findParent(a) == findParent(b) {
            print("YES")
        } else {
            print("NO")
        }
    }
}

/*
5 6
0 5 4
0 4 2
0 2 0
0 5 3
0 3 1
1 0 1
 */
