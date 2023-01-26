//
//  main.swift
//  알고리즘
//
//  Created by 배남석 on 2022/09/16.
//

import Foundation

// 4195_친구 네트워크

var t = Int(readLine()!)!

var parent = [String: String]()
var dic = [String: Int]()

func find(person: String) -> String {
    if person == parent[person] {
        return person
    }
    parent[person] = find(person: parent[person]!)
    return parent[person]!
}

func union(first: String, second: String) {
    let first = find(person: first)
    let second = find(person: second)
    
    if first != second {
        dic[first]! += dic[second]!
        parent[second] = first
    }
}

while t > 0 {
    parent = [:]
    dic = [:]
    let f = Int(readLine()!)!
    
    for _ in 0..<f {
        let input = readLine()!.split(separator: " ").map{String($0)}
        let first = input[0]
        let second = input[1]
        
        if !parent.keys.contains(first) {
            parent[first] = first
            dic[first] = 1
        }
        
        if !parent.keys.contains(second) {
            parent[second] = second
            dic[second] = 1
        }
        
        union(first: first, second: second)
        print(dic[find(person: first)]!)
    }
    
    t -= 1
}
