-- Haskell code by Claude Heiland-Allen
-- http://mathr.co.uk/blog/
-- http://math.bu.edu/people/bob/papers/monica.pdf
-- Geometry of the Antennas in the Mandelbrot Set
-- by R L Devaney and M Moreno-Rocha, April 11, 2000
-- ghci
-- :l b.hs
-- :main 1 2

import Control.Monad (forM_)
import Data.List (genericTake, genericDrop, intercalate)
import Data.Fixed (mod')
import Data.Ratio ((%), numerator, denominator)
import Numeric (readInt)
import System.Environment (getArgs)

type InternalAngle = Rational -- let pq = p % q

type ExternalAngle = ([Bool], [Bool]) -- tuple of lists ([preperiodic], [periodic])

-- convert bool value to char 0 or 1 
bit :: Bool -> Char
bit False = '0'
bit True = '1'


-- convert list of bool values to string of bits
bits :: [Bool] -> String
bits = map bit

-- converts tuple of the lists (pre, per) to the string
pretty :: ExternalAngle -> String
pretty (pre, per) =  bits pre ++ "(" ++ bits per ++")"

-- converts a list of bits to an Integer, by parsing a String.
binary :: [Bool] -> Integer
binary [] = 0
binary s = case readInt 2 (`elem`"01") (\c -> case c of '0' -> 0 ; '1' -> 1) (bits s) of
  [(b, "")] -> b

-- external angle from tuple form to rational number 
rational :: ExternalAngle -> Rational
rational (pre, per) = (binary pre % 2^p) + (binary per % (2^p * (2^q - 1)))
  where
    p = length pre
    q = length per


-- compute a tuple of external angles from internal angle
-- rays for such angles land on the root of pq wake =  wake angles = bulb
bulb :: InternalAngle -> (ExternalAngle, ExternalAngle) 
bulb pq = (([], bs ++ [False, True]), ([], bs ++ [True, False]))
  where
    q = denominator pq
    bs
      = genericTake (q - 2)
      . map (\x -> 1 - pq < x && x < 1)
      . iterate (\x -> (x + pq) `mod'` 1)
      $ pq
      
-- parents in the Farey tree
-- http://mathr.co.uk/blog/2016-10-31_finding_parents_in_the_farey_tree.html
parents :: InternalAngle -> (InternalAngle, InternalAngle)
parents pq = go q 1 0 p 0 1
  where
    p = numerator pq
    q = denominator pq
    go r1 s1 t1 r0 s0 t0
      | r0 == 0 =
          let ab = - s1 % t1
              a = numerator ab
              b = denominator ab
              c = p - a
              d = q - b
              cd = c % d
          in  (min ab cd, max ab cd)
      | otherwise =
          let (o, r) = divMod r1 r0
              s = s1 - o * s0
              t = t1 - o * t0
          in  go r0 s0 t0 r s t     
          
           
-- computa a list of external angles from internal angle
hub :: InternalAngle -> [ExternalAngle]
hub pq =
  -- List comprehension
  [ (sm, shift k sp) | k <- [0, b .. (q - p - 1) * b] ] ++
  [ (sp, shift k sp) | k <- [(q - p) * b, (q - p + 1) * b .. (q - 1) * b] ]
  where
    p = numerator pq
    q = denominator pq
    -- compute tuple of wake angles = bulb, 
    -- sm=s- < sp=s+ 
    (([], sm), ([], sp)) = bulb pq -- preperiod is 0 so empty list :  pre = []
    (ab, cd) = parents pq -- Farey parents
    b = denominator ab
    shift k = genericTake q . genericDrop k . cycle  -- shift map

main :: IO ()
main = do
  -- read the input 
  [sp, sq] <- getArgs
  p <- readIO sp
  q <- readIO sq
  -- compute
  let pq = p % q
      (lo, hi) = bulb pq
      hs = hub pq
  -- output the results    
  putStrLn $ "internal angle p/q = " ++ sp ++ " / " ++ sq 
  putStrLn $ "internal angle in lowest terms = "
  print pq
  putStrLn $ "rays of the bulb:"
  putStrLn $ pretty lo ++ " = " ++ show (rational lo)
  putStrLn $ pretty hi ++ " = " ++ show (rational hi)
  putStrLn $ ""
  putStrLn $ "rays of the principle hub:"
  forM_ hs $ \h -> putStrLn $ pretty h  ++ " = " ++ show (rational h)
