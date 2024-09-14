class Solution(object):
    def compareVersion(self, v1, v2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        l1 = v1.split('.')
        l2 = v2.split('.')
        s1=[]
        s2=[]
        for c in l1:
            s=int(c)
            s1.append(s)
        for c in l2:
            s=int(c)
            s2.append(s)

        
        while(len(s1)<len(s2)):
            s1.append(0)
        while(len(s2)<len(s1)):
            s2.append(0)
        for i in range(0,len(s1)):
            if s1[i]==s2[i]:
                continue
            elif s1[i]<s2[i]:
                return -1
            else:
                return 1
        print(s1,s2)
        # if s1==s2:  
        return 0
        # if int(s1)<int(s2) :
        #     return -1
        # else:
        #     return 1
        