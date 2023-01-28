//
//  File.swift
//  알고리즘
//
//  Created by 배남석 on 2022/11/09.
//

// 20055_컨베이어 벨트 위의 로봇

import Foundation

var input = readLine()!.split(separator: " ").map { Int(String($0))! }

let n = input[0]
let k = input[1]
var belt = [Bool]()
var naegu = [Int]()
input = readLine()!.split(separator: " ").map { Int(String($0))! }

for i in input {
    naegu.append(i)
    belt.append(false)
}

func lotation() {
    let last = naegu.removeLast()
    naegu.insert(last, at: 0)
    let lastBelt = belt.removeLast()
    belt.insert(lastBelt, at: 0)
    belt[n-1] = false
}

func move() {
    for i in stride(from: n-2, through: 0, by: -1) {
        if belt[i] {
            if naegu[i+1] > 0 && !belt[i+1]{
                naegu[i+1] -= 1
                belt[i+1] = true
                belt[i] = false
            }
        }
    }
    belt[n-1] = false
}

func calculate() -> Bool {
    var count = 0
    for i in naegu {
        if i == 0 {
            count += 1
        }
    }
    
    if count >= k {
        return false
    } else {
        return true
    }
}

var result = 0
while true {
    result += 1
    lotation()
    move()
    if naegu[0] > 0 {
        belt[0] = true
        naegu[0] -= 1
    }
    if !calculate() {
        print(result)
        break
    }
}
