# bed_baby
 Качалка для кровати ребёнка
Управление осуществляется через транзистор, двигатель наматывает на вал нить привязанную к кроватке чем создаёт качание.
В основной версии интенсивность качания задается потенциометром, чем больше параметр тем дольше работает двигатель и качание сильней.
В тестовой версии 3 режима переключаемых по тактовой кнопке.

В целом чем легче качается кровать и чем мощней двигатель тем меньше нужно время для 1 такта, подбирать только эксперементально.
Я использовал 5В двигатель от электроотвертки без редуктора (редуктор жужжит и на даёт работать обратному ходу), в идеале можно использвать от шуруповерта на 12В.
Полевой транзистор нашел в старом БП компьютера, транзистор нужен мощный, на 15-20А минимум (пиковый ток на старте большой иначе сильно греется транзистор) при напряжении на затворе в 5В, в идеале чтоб на 5В уже открывался полностью.
БП использовал от старого ПК (что было под рукой).
В прошивке включен расширенный ШИМ для меньшей нагрузки на транзистор и двигатель.