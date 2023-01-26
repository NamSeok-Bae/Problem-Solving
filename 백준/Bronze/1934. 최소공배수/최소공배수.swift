//
//  main.swift
//  백준
//
//  Created by 배남석 on 2021/07/16.
//

import Foundation

var startIndex = Int(readLine()!)!

for _ in 0..<startIndex {
    let a = readLine()!.split(separator: " ").map{Int($0)!}
    print("\((a[0] * a[1]) / gcd(first: a[0], second : a[1]))")
}

func gcd(first : Int, second : Int) -> Int {
    var a = first
    var b = second
    var cmp: Int = 0
    while true {
        if a%b == 0 {
            return b
        }
        else
        {
            a = (a/b) * b + a%b
            cmp = a%b
            a = b
            b = cmp
        }
    }
}
