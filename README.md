# Jane Street's puzzle for the IMO 2022 
This project was made by [Kirill Zolotuskiy](https://www.imo-official.org/participant_r.aspx?id=31510) (ISL2) to find all solutions for a puzzle created by [Jane Street](https://www.janestreet.com/) for the [IMO 2022](https://www.imo2022.org/).   

## Rules
![](/stuff/photo.jpg)   
The puzzle is a grid filled with 50 squares. Each square has either month, day of the month or weekday (7 + 12 + 31 = 50). 
There are also 10 different pieces that you need to fill the grid with. When you fill the grid, there will be 3 squares left that need to make up a date (ex. Mon Jan, 1). The goal is to find a new date that no one has discovered yet.   

## How to visualize solutions
You can use [imo_puzzle_visualizer_v2.exe](/imo_puzzle_visualizer_v2.exe) or you can recompile [imo_puzzle_visualizer_v2.cpp](/imo_puzzle_visualizer_v2.cpp). Then you just need to run the visualizer and paste the code (ex. 1010100042252222 1647304430505023).   
Example:   
```
>>> 1010100042252222 1647304430505023

|JA|  |__ __   |  |##|
|  |   __ __|  |  |##|
|  |__|__   |__|  |  |
|  |   __|  |__ __|  |
|__|  |__ __|  |   __|
|__ __|  |   __|__|28|
|__ __ __|__|     |WE|
|##|##|##|##|__ __ __|
```

## Solutions
### All solutions
According to my program, there are 9 728 191 valid solutions that are listed [here](/all_solutions.txt). **Warning:** This file uses [github lfs](https://git-lfs.github.com/), if the link does not work you cat try [https://github.com/Kirill-iceland/IMO22_puzzle/blob/master/all_solutions.txt](https://github.com/Kirill-iceland/IMO22_puzzle/blob/master/all_solutions.txt) and either download the file or view it raw.
### All dates
[Here](/all_dates.txt) is a list with one solution for each date.   

[<img src="https://upload.wikimedia.org/wikipedia/commons/c/c9/Jane_Street_Capital_Logo.svg" width="49%"/>
](https://www.janestreet.com/) [<img src="https://assets.swoogo.com/uploads/1572205-61fbd7c2726b0.svg" width="49%"/>](https://www.imo2022.org/)
