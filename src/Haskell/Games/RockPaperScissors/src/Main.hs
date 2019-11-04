module Main where

import System.IO
import System.Random
import Game
import Beauty

data Answer = Yes | No

instance Read Answer where
  readsPrec _ "y" = [(Yes, "")]
  readsPrec _ "n" = [(No, "")]
  readsPrec _  _  = []

randomInt :: Int -> Int -> IO Int
randomInt from to = do
  g <- getStdGen
  let (x, _) = randomR (from, to) g
  return x

randomWeapon :: IO Weapon
randomWeapon = do
  x <- randomInt 1 3
  return (x |> asWeapon)

asWeapon :: Int -> Weapon
asWeapon 1 = Rock
asWeapon 2 = Paper
asWeapon 3 = Scissors

ask :: (Read a) => String -> IO a
ask question = do
  question |> toConsoleLn
  answer   <- fromConsoleLn

  return <| parsed answer

loop :: IO ()
loop = do
  player <- ask "Pick weapon: "
  ai     <- randomWeapon

  player `vs` ai
    |> asText
    |> toConsoleLn

  answer <- ask "Wanna repeat? (y/n)"
  continueWith answer

end :: IO ()
end = "Finish!" |> toConsoleLn

continueWith :: Answer -> IO ()
continueWith Yes = loop
continueWith No  = end

main :: IO ()
main = do
  hSetBuffering stdout NoBuffering

  loop
