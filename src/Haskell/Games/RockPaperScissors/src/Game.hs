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
Rock     `vs` Rock     = Win
Rock     `vs` Scissors = Lose
Rock     `vs` Paper    = Draw
