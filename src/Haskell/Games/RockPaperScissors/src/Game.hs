module Game where

data Weapon = Rock
            | Paper
            | Scissors
            deriving (Show, Read)

data Result = Win
            | Lose
            | Draw
            deriving (Show)

weaponOf :: String -> Weapon
weaponOf = read

vs :: Weapon -> Weapon -> Result
vs Scissors Paper    = Win
vs Scissors Rock     = Lose
vs Scissors Scissors = Draw
vs Paper    Rock     = Win
vs Paper    Scissors = Lose
vs Paper    Paper    = Draw
vs Rock     Scissors = Win
vs Rock     Paper    = Lose
vs Rock     Rock     = Draw
