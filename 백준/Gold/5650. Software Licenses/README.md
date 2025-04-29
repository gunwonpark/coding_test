# [Gold V] Software Licenses - 5650 

[문제 링크](https://www.acmicpc.net/problem/5650) 

### 성능 요약

메모리: 2208 KB, 시간: 0 ms

### 분류

그리디 알고리즘

### 제출 일자

2025년 4월 29일 23:24:20

### 문제 설명

<p>You are starting a security company that needs to obtain licenses for n different pieces of cryptographic software. Due to regulations, you can only obtain these licenses at the rate of at most one per month.</p>

<p>Currently the license i is selling for a price of Pi dollars. However, they are all becoming more expensive according to exponential growth curves: in particular, the cost of license i increases by a factor of Ri > 1. This means that if license i is purchased t months from now, it will cost P<sub>i</sub> * (R<sub>i</sub>)<sup>t</sup> dollars.</p>

<p>Given a set of n license prices and their growth factors, you have to plan the purchase of these licenses within n months in order to minimize the total cost.</p>

<p>For example, you need to buy licenses A, B, C, D. Their prices and factors are the following. P<sub>A</sub> = 200, R<sub>A</sub> = 1.01, P<sub>B</sub> = 300, R<sub>B</sub> = 1.12, P<sub>C</sub> = 400, R<sub>C</sub> = 1.05, P<sub>D</sub> = 650, R<sub>D</sub> = 1.10</p>

<p>You can buy all needed licenses within 4 months. To obtain the minimum cost of 1,633.06 dollars you have to purchase D in the first month (with its initial price), then B in the second month, and then C in the third month and A in the last month. </p>

### 입력 

 <p>The first line contains a positive integer n 1( ≤ n ≤ 100) indicating the number of licenses you need. The next n lines contain 2 numbers: P<sub>j</sub> and R<sub>j</sub> in each line.</p>

### 출력 

 <p>The output is the minimum cost that you have to pay. The number must be rounded to 2 decimal places.</p>

