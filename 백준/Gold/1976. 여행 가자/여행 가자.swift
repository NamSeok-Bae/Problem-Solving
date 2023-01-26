//
//  main.swift
//  알고리즘
//
//  Created by 배남석 on 2022/09/14.
//

import Foundation

// 1976_여행가자

func findParent(_ a: Int) -> Int {
    if a == parent[a] {
        return a
    }
    
    return findParent(parent[a])
}

func union(_ a: Int, _ b: Int) {
    let a = findParent(a)
    let b = findParent(b)
    
    if a != b {
        parent[a] = b
    }
}

var n = Int(readLine()!)!
var m = Int(readLine()!)!

var parent = Array(0...n)

for i in 1...n {
    let input = readLine()!.split(separator: " ").map({ Int(String($0))! })
    for j in 0..<input.count {
        if input[j] == 1 {
            union(i, j + 1)
        }
    }
}

var input = readLine()!.split(separator: " ").map({ Int(String($0))! })

var temp = input[0]
var isAble = true

for i in 1..<m {
    if findParent(temp) != findParent(input[i]) {
        isAble = false
        break
    } else {
        temp = input[i]
    }
}

if isAble {
    print("YES")
} else {
    print("NO")
}
