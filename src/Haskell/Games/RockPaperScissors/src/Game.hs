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
Scissors `vs` Paper    = Win
Scissors `vs` Rock     = Lose
Scissors `vs` Scissors = Draw
Paper    `vs` Rock     = Win
Paper    `vs` Scissors = Lose
Paper    `vs` Paper    = Draw
Rock     `vs` Scissors = Win
Rock     `vs` Paper    = Lose
Rock     `vs` Rock     = Draw
