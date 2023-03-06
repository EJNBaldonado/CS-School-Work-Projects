#ECON129 Term Project
#Effect of COVID-19 on Financial state of Hospitals // Reasons behind them
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import seaborn as sns
import warnings
from pylab import rcParams
import scipy.stats as stats

np.random.seed(8)
warnings.filterwarnings('ignore')
rcParams['figure.figsize'] = 20, 10
rcParams['font.size'] = 30
sns.set()

HospitalData2018 = pd.read_csv("HospitalData2018.csv")
HospitalData2020 = pd.read_csv("HospitalData2020.csv")

# CREATE ANALYZE FUNCTION: 
def Analyze(df, ATTR):
    attr2020 = ATTR + '_y'
    attr2018 = ATTR + '_x'

    # CLEAN DATA (remove default 0)
    df = df[df[attr2020] != 0]
    df = df[df[attr2018] != 0]

    plt1 = plt.figure()
    ax1 = sns.distplot(df[attr2020])
    plt.axvline(np.mean(df[attr2020]), color = "Red", linestyle = "dashed", linewidth = 5)
    _, max_ = plt.ylim()
    plt.text(
        df[attr2020].mean() + df[attr2020].mean() / 10,
        max_ - max_ / 10,
        "Mean: {:.2f}".format(df[attr2020].mean()),
    )
    plt1.show()
    
    plt2 = plt.figure()
    ax2 = sns.distplot(df[attr2018])
    plt.axvline(np.mean(df[attr2018]), color = "Red", linestyle = "dashed", linewidth = 5)
    _, max_ = plt.ylim()
    plt.text(
        df[attr2018].mean() + df[attr2018].mean()/ 10,
        max_ - max_ / 10,
        "Mean: {:.2f}".format(df[attr2018].mean()),
    )
    plt2.show()

    df[('\'' + ATTR + '\'')] = df[attr2020] - df[attr2018]
    print('Average change in 2020 from 2018 for '+ ATTR + ' is ' + str(df['\'' + ATTR + '\''].mean()))

    stat, p = stats.ttest_1samp(df[('\'' + ATTR + '\'')], 0, alternative = 'two-sided' )
    print('Test statistic=%.3f, p-value=%.3f' % (stat, p))
    if p > 0.10:
        print('For α = .10, there is insufficient evidence to conclude that there is an effect on ' + ATTR + ' between 2018 and 2020.')
    else:
        print('For α = .10, there is sufficient evidence to conclude that there is an effect on ' + ATTR + ' between 2018 and 2020.')

# DATA CLEANING
HospitalData2018 = HospitalData2018.replace(',','', regex = True)
HospitalData2020 = HospitalData2020.replace(',','', regex = True)


# DATA MANIPULATION (STRINGS TO FLOAT)
x = HospitalData2018.select_dtypes(object).columns
HospitalData2018[x] = HospitalData2018[x].apply(pd.to_numeric, errors = 'coerce')

x = HospitalData2020.select_dtypes(object).columns
HospitalData2020[x] = HospitalData2020[x].apply(pd.to_numeric, errors = 'coerce')


# MERGE TABLES TO MATCH HOSPITALS IN 2018 TO 2020
Joined1820 = pd.merge(HospitalData2018, HospitalData2020, on='FAC_NO')

df = Joined1820
attr = str(input('Insert an attribute from the Hospital attribute documentation: '))
attr_x = attr + '_x'
attr_y = attr + '_y'
while attr_x in df.columns or attr_y in df.columns:
    Analyze(df, attr)
    attr = str(input('Insert an attribute from the Hospital attribute documentation: '))
    attr_x = attr + '_x'
    attr_y = attr + '_y'


