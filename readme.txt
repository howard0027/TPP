<<Player>> : 我覺得它寫在在class Game會比較好(?，而不是class Map裡面。
1. Player() constructor : default，因為不知道map大小，所以會將Player::pos=0。
2. Player(sz) constructor : 傳入有多少塊lands(要知道map大小)，會將Player::pos=[0, sz)。
3. move(sz) : 傳入有多少塊lands(要知道map大小)，會在map內移動，更新Player::pos。
4. getPos() : 得到Player::pos
5. addCoin(delta) : 傳入delta，代表增減多少錢(如果減少是負數、增加是正數)，更新Player::coin。我用assert檢查Player::coin<0，但這只能在測試使用，所以看要在哪裡做檢查。

<<Zombie>> : 我覺得它寫在在class Game會比較好(?，而不是class Map裡面。另外可能有一些冗餘功能XD。
1. Zombie() constructor : default，因為不知道map大小，所以會將Zombie::pos=0。
2. Zombie(sz) constructor : 傳入有多少塊lands(要知道map大小)，會將Zombie::pos=[0, sz)。
3. move(sz) : 傳入有多少塊lands(要知道map大小)，會在map內移動，更新Zombie::pos。
4. getHP() : 得到Zombie::hp
5. getAtk() : 得到Player::atk
6. getPos() : 得到Zombie::pos
7. attack(Plant &) : 執行zombie act (這部分的功能可能與Game重複??)
8. print() : 用視覺化的方式印出這一支zombie的information (這部分的功能可能與Game重複??)

<<Map>> 因為變數都是private，所以我有增加幾個函數方便得到private的資料。
1. Map(sz) constructor: 傳入有多少個lands in this map。
2. getPlantByIndexOfLand(index) : 傳入[0, numOfLands-1]，表示要找在編號index的land上的Plant，回傳對應的Plant*(是指標)，如果該land沒有種植植物，回傳nullptr。
3. planting(index, Plant* plant) : 在編號index的land上種plant。我沒有檢查是否已經有別的plant喔!
4. checkStatus() : 我目前是回傳plantAmount的數量是否為0。(我不太清楚規則是不是只有這一條。)