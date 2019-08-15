#PIC16
#Assignment7F
#Li, Chak Yin (Anders)
#704950093

import plotly
import plotly.plotly as py
import plotly.graph_objs as go

plotly.tools.set_credentials_file(username = 'AndersL', api_key = 'l4XxYKBFo7wSNlup3Zjh')

x1 = py.get_figure("https://plot.ly/~dfreder1/69/")['data'][0]['x']

new_data = [year for year in x1 if year > 1900]

range_of_years = range(1900,2020,10)

dictOfYears = {i: new_data.count(i) for i in set(new_data)}

x = dictOfYears.keys()[1:]

y = [dictOfYears[i] for i in x]

def cumulative(lst):
    for i in range(len(lst)):
        if i != 0:
            lst[i] += lst[i-1]
    x = lst
    return x

new_y = cumulative(y[:])

trace1 = go.Scatter(x=x,y=new_y,mode='lines',line={'color':'orange'},fill='tozeroy',fillcolor='rgba(255,165,0,0.5)',marker={'color':'orange'})

data = go.Data([trace1])

layout = go.Layout(autosize=False, width=600,height=400,font={'family':'Times New Roman'},title = 'Total Bridges Built in CA Since 1900', xaxis={'title':'Year', 'showgrid':True,'dtick':10, 'autorange':False, 'range' : [1900,2010]},yaxis={'title':'Total Bridges', 'dtick': 5000})

figure = go.Figure(data = data, layout = layout)

py.iplot(figure, filename = 'Assignment7F')

py.image.save_as(figure, filename = 'Assignment7F.png')

print 'Done'
