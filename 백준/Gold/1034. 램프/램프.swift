//
//  main.swift
//  알고리즘
//
//  Created by 배남석 on 2022/09/07.
//

import Foundation

// 1034_램프

struct Data {
    var Name = ""
    var patternCnt = 0
    var zeroCnt = 0
}

var input = readLine()!.split(separator: " ").map { Int($0)! }
var n = input[0]
var m = input[1]
var array: [String:(Int,Int)] = [:]
var result = 0

for _ in 0..<n {
    let strInput = readLine()!
    if array[strInput] == nil {
        array[strInput] = (1,0)
    } else {
        array[strInput]?.0 += 1
    }
    
    if array[strInput]?.1 == 0 {
        let strArr = Array(strInput).map({String($0)})
        var cnt = 0
        
        for j in strArr {
            if j == "0" {
                cnt += 1
            }
        }
        array[strInput]!.1 = cnt
    }
}

var k = Int(readLine()!)!

for i in array {
    let cnt = i.value.1
    if cnt <= k && cnt % 2 == k % 2 {
        result = max(result, i.value.0)
    }
}

print(result)
