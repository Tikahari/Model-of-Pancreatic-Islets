size="5"
run="0_model_1"
touch log.txt
python3 Super.py $size >> log.txt
echo "------------ Super.py complete ----------" >> log.txt
python3 Compile.py $run -1 $size >> log.txt
echo "------------ Compile.py complete ----------" >> log.txt
#python3 Model.py $run -1 0.15 0.75 $size -1 -1 -1 -1 >> log.txt
echo "------------ Model.py complete ----------" >> log.txt
# bash Super.sh
