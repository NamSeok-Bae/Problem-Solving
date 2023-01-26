//
//  main.swift
//  알고리즘
//
//  Created by 배남석 on 2022/09/06.
//

import Foundation

// 1700 - 멀티탭 스케쥴링

var input = readLine()!.split(separator: " ").map({Int($0)!})
var n = input[0]
var k = input[1]

input = readLine()!.split(separator: " ").map({Int($0)!})
var multiTap = Array(repeating: 0, count: n)
var result = 0

while(!input.isEmpty) {
    let cur = input.removeFirst()
    
    if multiTap.contains(cur) {
        continue
    } else if let index = multiTap.firstIndex(of: 0) {
        multiTap[index] = cur
        continue
    }
    
    var maxIndex: Int = 0
    var maxNum: Int = 0
    var isChanged: Bool = false
    
    for (num,i) in multiTap.enumerated() {
        if let index = input.firstIndex(of: i) {
            if maxIndex < index {
                maxIndex = index
                maxNum = num
            }
        } else {
            multiTap[num] = cur
            result += 1
            isChanged = true
            break
        }
    }
    
    if !isChanged {
        result += 1
        multiTap[maxNum] = cur
    }
}
print(result)
