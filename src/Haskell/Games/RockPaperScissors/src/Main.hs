module Main where

import System.IO
import Game

ioWeapon :: IO Weapon
ioWeapon = do
  putStr "Pick weapon: "
  line <- getLine
  return $ weaponOf line

end :: IO ()
end = putStrLn "Finish!"

loop :: IO ()
loop = do
  player <- ioWeapon
  ai     <- ioWeapon

  putStrLn $ show $ player `vs` ai
  end

main :: IO ()
main = do
  hSetBuffering stdout NoBuffering

  loop
