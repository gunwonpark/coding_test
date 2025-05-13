# [Gold IV] Game of RUN - 33801 

[문제 링크](https://www.acmicpc.net/problem/33801) 

### 성능 요약

메모리: 56744 KB, 시간: 76 ms

### 분류

수학, 다이나믹 프로그래밍, 조합론

### 제출 일자

2025년 5월 13일 09:04:55

### 문제 설명

<p>Game of RUN은 Game of Go(바둑)와 비슷하지만 2차원의 정사각형 격자 대신에 1차원 격자를 사용하는 2인용 게임이다.</p>

<p>Game of RUN의 규칙은 다음과 같다.</p>

<ul>
	<li>두 플레이어가 번갈아서 흑돌 또는 백돌을 격자 위에 원하는 만큼 놓는다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 108.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container>개를 놓는 것도 허용된다.</li>
	<li>한 가지 색깔의 돌이 1칸 이상의 연속한 구간을 차지할 때 그 구간 전체를 그룹이라고 하자. 흑돌 3개가 연달아 놓여 있다면 그 중 흑돌 2개나 1개만을 포함하는 구간은 그룹이 아니다. 이때, 모든 그룹은 적어도 하나의 빈 칸과 이웃하고 있어야 한다. 예를 들어, 아래와 같은 경우들은 각각 흑돌의 그룹과 백돌의 그룹이 빈 칸과 이웃하고 있지 않으므로 올바른 게임 상태가 아니다.</li>
</ul>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/89604c57-9fd5-4532-bbf8-15425c505721/-/preview/" style="height: 100px; width: 800px;"></p>

<p>길이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 108.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container>인 게임판에서 가능한 모든 서로 다른 게임 상태의 수를 <mjx-container class="MathJax" jax="CHTML" style="font-size: 108.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c37"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mn>000</mn><mn>000</mn><mn>007</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 000 000 007$</span></mjx-container>로 나눈 나머지를 구하시오.</p>

### 입력 

 <p>첫 번째 줄에 테스트 케이스의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 108.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T$</span></mjx-container>가 주어진다.</p>

<p>그다음 <mjx-container class="MathJax" jax="CHTML" style="font-size: 108.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T$</span></mjx-container>줄에 걸쳐서 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 108.8%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container>의 값이 한 줄에 하나씩 주어진다.</p>

### 출력 

 <p>각 테스트 케이스에 대해 문제의 정답을 한 줄에 출력한다.</p>

