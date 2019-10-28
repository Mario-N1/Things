module Game where

win :: String -> String -> Bool
win "Scissors" "Paper" = True
win "Scissors" "Stone" = False
win "Paper"    "Stone"    = True
win "Paper"    "Scissors" = False
win "Stone"    "Scissors" = True
win "Stone"    "Paper"    = False

lose :: String -> String -> Bool
lose x y = not $ win x y

draw :: String -> String -> Bool
draw x y = x == y
