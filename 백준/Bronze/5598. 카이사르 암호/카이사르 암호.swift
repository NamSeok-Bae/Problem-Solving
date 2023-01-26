//
//  main.swift
//  백준
//
//  Created by 배남석 on 2021/07/16.
//

import Foundation

let arr = Array(readLine()!).map{String($0)}

var crr = [Character]()

var x: UInt8 = 0

for i in arr.indices {
    x = Character(arr[i]).asciiValue! - 3
    if x < 65 {
        x = x + 26
    }
    crr.append(Character(UnicodeScalar(x)))
}
print(crr.map{"\($0)"}.joined())
