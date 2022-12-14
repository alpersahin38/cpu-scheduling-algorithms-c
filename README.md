                                              # CPU SCHEDULİNG ALGORİTMALARINA İLİŞKİN PERFORMANS METRİKLERİNİN DİNAMİK OLARAK 
                                                                           # HESAPLANMASI
                                                                          
                                                                          
## CPU Scheduling (İşlemci Zamanlaması) Algoritmaları

### First – Come, First-Served (FCFS) Scheduling 
FIFO (First In First Out) yada diğer bilinen adıyla FCFS (First Come First Served) stratejisinde bekleme sırasına giren
prosesler sıranın en başından seçilerek işlemciye aktarılır.

Output:
![image](https://user-images.githubusercontent.com/93208734/207586929-6db57f88-041d-4f61-ad2d-a52e29fb6be1.png)


### Shortest Job First
Bir zamanlama algoritması (CPU Scheduling) şekli olan en kısa iş ilk (Shortest job first, SJF veya Shortest Job Next, SJN) algoritmasında
o anda elde bulunan işler biritilmek için gereken süreye göre sıralanırlar. En kısa olan işe öncelik verilerek sırayla işler alınır.
Çalışma mantığı olarak kesintisiz (non-preemptive) bir algoritma olan bu yaklaşımda bir iş başladıktan sonra başka bir işin araya girme şansı yoktur. 
Basitçe eldeki işlerin en kısasını yaparak performans artışı sağlamaya çalışır. Ancak algoritmanın bir dez avantajı kıtlık (starvation) doğurma riskidir.

Output:
![image](https://user-images.githubusercontent.com/93208734/207587328-ea32251c-afd2-485d-bd3a-5ffcf80618bf.png)

![image](https://user-images.githubusercontent.com/93208734/207587351-bbbc3fb4-7c0d-46e0-8b2e-d89f7e3ef2a3.png)


### Round Robin
Bir zamanlama (scheduling) algoritmasıdır. Özellikle işletim sistemi tasarımında işlemcinin (CPU) zamanlamasında kullanılan meşhur algoritmalardan birisidir.
Bu algoritmaya göre sırası gelen işlem, işlemcide işi bitmese bile belirli bir zaman biriminden sonra (time quadrant) işlemciyi terk etmek zorundadır.
Bu sayed işletim sisteminde kıtlık (Starvation) olma ihtimali kalmaz. Çünkü hiç bir zaman bir işlemin CPU’yu alıp diğer işlemlere sıra gelmesini engellemesi mümkün olmaz.

Output:
![image](https://user-images.githubusercontent.com/93208734/207587627-939bbdbd-4da4-47db-9828-8601c3f395a6.png)


### Priority Scheduling
Her bir işleme öncelik sayısı (tamsayı) atanır. CPU en öncelikli olan işleme tahsis edilir.
Preemptive(Kesilebilen işlem) ise işlem devam etse dahi o an daha öncelikli bir işlem geldiğinde yarıda kesilip öncelikli işlem yapılır.
Nonpreemptive(Kesilemeyen işlem)’lerde ise işlem tamamlandıktan sonra en yüksek öncelik kimde ise CPU’yu o işlem kullanır.
Bu algoritmanın yanında getirdiği bir problem vardır. Bu da Starvation problemidir(açlık). Düşük öncelikli bir işlem üzerine ondan daha öncelikli 
işlemlerin çokça gelmesi durumunda az öncelikli işlemimiz asla CPU’yu kullanamaz. Bu sorunu gidermek için bir çözüm de vardır.
Aging yöntemi(yaşlandırma) önüne aldığı her işlemde bu önceliği az olan işlemimizin önceliğini yavaş yavaş artırırız. Böylece bu önceliksiz 
işlem de sistem kaynaklarından yararlanabilir.
Output:
![image](https://user-images.githubusercontent.com/93208734/207587744-0c8b278f-d5e4-4caa-8016-ad63f8cb604a.png)


