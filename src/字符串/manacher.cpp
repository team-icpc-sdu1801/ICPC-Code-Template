void Manacher(char s[],int len) {//原字符串和串长
    int l = 0;
    String[l++] = '$'; // 0下标存储为其他字符,防止越界
    String[l++] = '#';
    for (int i = 0; i < len; i++) {
        String[l++] = s[i];
        String[l++] = '#';
    }
    String[l] = 0; // 空字符
    int MaxR = 0;
    int flag = 0;
    for (int i = 0; i < l; i++) {
        cnt[i] = MaxR > i ? min(cnt[2 * flag - i], MaxR - i) : 1;//2*flag-i是i点关于flag的对称点
        while (String[i + cnt[i]] == String[i - cnt[i]])
            cnt[i]++;
        if (i + cnt[i] > MaxR) {
            MaxR = i + cnt[i];
            flag = i;
        }
    }
}
/*
* String: $ # a # b # a # a # b # a # 0
* cnt:    1 1 2 1 4 1 2 7 2 1 4 1 2 1 
*/