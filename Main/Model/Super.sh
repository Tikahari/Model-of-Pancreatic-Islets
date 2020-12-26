size="5"
run="0_model_0"
touch log.txt
python3 Super.py $size $run >> log.txt
echo "------------ Super.py complete ----------" >> log.txt
python3 Compile.py $run -1 $size >> log.txt
echo "------------ Compile.py complete ----------" >> log.txt
python3 Model.py $run IND 0.15 0.75 $size -1 -1 -1 -1
echo "------------ Model.py complete ----------" >> log.txt
# bash Super.sh
